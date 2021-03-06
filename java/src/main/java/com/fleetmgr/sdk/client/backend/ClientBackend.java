package com.fleetmgr.sdk.client.backend;

import java.util.logging.Level;
import com.fleetmgr.interfaces.Location;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.FacadeServiceGrpc;
import com.fleetmgr.sdk.client.Client;
import com.fleetmgr.sdk.client.core.CoreClient;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import io.grpc.ManagedChannel;
import io.grpc.netty.shaded.io.grpc.netty.GrpcSslContexts;
import io.grpc.netty.shaded.io.grpc.netty.NegotiationType;
import io.grpc.netty.shaded.io.grpc.netty.NettyChannelBuilder;
import io.grpc.netty.shaded.io.netty.handler.ssl.SslContext;
import io.grpc.netty.shaded.io.netty.handler.ssl.SslContextBuilder;
import io.grpc.stub.StreamObserver;

import javax.net.ssl.SSLException;
import java.io.File;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.TimeUnit;

/**
 * Created by: Bartosz Nawrot
 * Date: 07.12.2018
 * Description:
 */
public class ClientBackend implements StreamObserver<ControlMessage> {

    private Client client;
    private Client.Listener clientListener;

    private ExecutorService executor;

    private CoreClient core;

    private HeartbeatHandler heartbeatHandler;
    private ChannelsHandler channelsHandler;

    private ManagedChannel channel;
    private StreamObserver<ClientMessage> toFacade;

    public ClientBackend(Client client,
                         Client.Listener clientListener,
                         ExecutorService executor,
                         CoreClient core) {
        this.client = client;
        this.clientListener = clientListener;

        this.executor = executor;

        this.core = core;

        this.heartbeatHandler = new HeartbeatHandler(client, this);
        this.channelsHandler = new ChannelsHandler(client, executor);
    }

    public ExecutorService getExecutor() {
        return executor;
    }

    public CoreClient getCore() {
        return core;
    }

    public HeartbeatHandler getHeartbeatHandler() {
        return heartbeatHandler;
    }

    public ChannelsHandler getChannelsHandler() {
        return channelsHandler;
    }

    Location getLocation() {
        return clientListener.getLocation();
    }

    public void openFacadeConnection(String ip, int port) throws SSLException {
        SslContext sslContext =
                buildSslContext("grpc_facade.crt",
                        null,
                        null);

        channel = NettyChannelBuilder.forAddress(ip, port)
                .negotiationType(NegotiationType.TLS)
                .sslContext(sslContext)
                .overrideAuthority("localhost")
                .build();

        FacadeServiceGrpc.FacadeServiceStub stub = FacadeServiceGrpc.newStub(channel);
        toFacade = stub.control(this);
    }

    protected void closeFacadeConnection() {
        toFacade.onCompleted();
    }

    public void closeFacadeChannel() {
        try {
            channel.shutdown().awaitTermination(1, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void send(ClientMessage message) {
        trace("Sending:\n" + message + "@ " + client.getStateName());
        toFacade.onNext(message);
    }

    @Override
    public void onNext(ControlMessage message) {
        client.notifyEvent(new Received(message));
    }

    @Override
    public void onError(Throwable t) {
        t.printStackTrace();
        client.notifyEvent(new ConnectionEvent(ConnectionEvent.Type.ERROR));
    }

    @Override
    public void onCompleted() {
        client.notifyEvent(new ConnectionEvent(ConnectionEvent.Type.CLOSED));
    }

    public void trace(String message) {
        client.log(Level.INFO, message);
    }

    @SuppressWarnings("SameParameterValue")
    private static SslContext buildSslContext(String trustCertCollectionFilePath,
                                              String clientCertChainFilePath,
                                              String clientPrivateKeyFilePath) throws SSLException {
        SslContextBuilder builder = GrpcSslContexts.forClient();
        if (trustCertCollectionFilePath != null) {
            builder.trustManager(new File(trustCertCollectionFilePath));
        }
        if (clientCertChainFilePath != null && clientPrivateKeyFilePath != null) {
            builder.keyManager(new File(clientCertChainFilePath), new File(clientPrivateKeyFilePath));
        }
        return builder.build();
    }
}
