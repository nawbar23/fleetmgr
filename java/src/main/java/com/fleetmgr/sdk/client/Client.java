package com.fleetmgr.sdk.client;

import com.fleetmgr.sdk.client.core.CoreClient;
import com.fleetmgr.sdk.client.event.input.Event;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.output.facade.FacadeEvent;
import com.fleetmgr.interfaces.Location;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.FacadeServiceGrpc;
import com.fleetmgr.sdk.system.machine.StateMachine;
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
 * Date: 04.09.2018
 * Description:
 */
public abstract class Client extends StateMachine<Event>
        implements StreamObserver<ControlMessage>  {

    public interface Listener {
        Location getLocation();
        void onEvent(FacadeEvent event);
        void trace(String message);
    }

    private Listener listener;

    private ManagedChannel channel;
    private StreamObserver<ClientMessage> toFacade;

    CoreClient coreClient;

    Client(String coreAddress, String key, Listener listener, ExecutorService executor) {
        super(executor, null);
        this.listener = listener;

        this.coreClient = new CoreClient(coreAddress, key);
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
        trace("Sending:\n" + message + "@ " + getStateName());
        toFacade.onNext(message);
    }

    public Location getLocation() {
        return listener.getLocation();
    }

    @Override
    public void onNext(ControlMessage message) {
        notifyEvent(new Received(message));
    }

    @Override
    public void onError(Throwable t) {
        t.printStackTrace();
        notifyEvent(new ConnectionEvent(ConnectionEvent.Type.ERROR));
    }

    @Override
    public void onCompleted() {
        notifyEvent(new ConnectionEvent(ConnectionEvent.Type.CLOSED));
    }

    @Override
    public void trace(String message) {
        listener.trace(message);
    }

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
