package com.fleetmgr.sdk.client.backend;

import com.fleetmgr.interfaces.Location;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.FacadeServiceGrpc;
import com.fleetmgr.sdk.client.Client;
import com.fleetmgr.sdk.client.core.CoreClient;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.traffic.Channel;
import com.fleetmgr.sdk.client.traffic.UdpChannel;
import io.grpc.ManagedChannel;
import io.grpc.netty.shaded.io.grpc.netty.GrpcSslContexts;
import io.grpc.netty.shaded.io.grpc.netty.NegotiationType;
import io.grpc.netty.shaded.io.grpc.netty.NettyChannelBuilder;
import io.grpc.netty.shaded.io.netty.handler.ssl.SslContext;
import io.grpc.netty.shaded.io.netty.handler.ssl.SslContextBuilder;
import io.grpc.stub.StreamObserver;

import javax.net.ssl.SSLException;
import java.io.File;
import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.TimeUnit;

/**
 * Created by: Bartosz Nawrot
 * Date: 07.12.2018
 * Description:
 */
public class ClientBackend implements StreamObserver<ControlMessage> {

    public interface Listener {
        void trace(String message);
    }

    private Listener listener;

    private Client client;
    private Client.Listener clientListener;

    private ExecutorService executor;

    private HeartbeatHandler heartbeatHandler;

    private HashMap<Long, Channel> sockets;

    private CoreClient core;

    private ManagedChannel channel;
    private StreamObserver<ClientMessage> toFacade;

    public ClientBackend(Listener listener,
                         Client client,
                         Client.Listener clientListener,
                         ExecutorService executor,
                         CoreClient core) {
        this.listener = listener;
        this.client = client;
        this.clientListener = clientListener;

        this.executor = executor;

        this.heartbeatHandler = new HeartbeatHandler(client, this);

        this.sockets = new HashMap<>();
        this.core = core;
    }

    public ExecutorService getExecutor() {
        return executor;
    }

    public HeartbeatHandler getHeartbeatHandler() {
        return heartbeatHandler;
    }

    public HashMap<Long, Channel> getSockets() {
        return sockets;
    }

    public CoreClient getCore() {
        return core;
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

    public Map<Long, Channel> validateChannels(Collection<com.fleetmgr.interfaces.Channel> channels) {
        Map<Long, Channel> opened = new HashMap<>();
        for (com.fleetmgr.interfaces.Channel c : channels) {
            try {
                trace("Opening channel id: " + c.getId());
                UdpChannel socket = new UdpChannel(executor,
                        c.getIp(), c.getPort(), c.getId(), new DefaultSocketListener());
                socket.initialize(c.getRouteKey());
                sockets.put(c.getId(), socket);
                opened.put(c.getId(), socket);
                trace("Channel id: " + c.getId() + " VALIDATED");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return opened;
    }

    public void closeChannels(Collection<Long> channels) {
        for (Long c : channels) {
            trace("Closing channel, id: " + c);
            Channel s = sockets.remove(c);
            if (s != null) {
                s.close();
            } else {
                trace("Warning, trying to close not existing channel, id: " + c);
            }
        }
    }

    public void closeAllChannels() {
        for (Channel s : sockets.values()) {
            trace("Closing channel id: " + s.getChannelId());
            s.close();
        }
        sockets.clear();
    }

    Location getLocation() {
        return clientListener.getLocation();
    }

    public void trace(String message) {
        listener.trace(message);
    }

    private class DefaultSocketListener implements Channel.Listener {
        @Override
        public void onReceived(Channel channel, byte[] data, int size) {
        }

        @Override
        public void onClosed(Channel channel) {
        }

        @Override
        public void trace(String message) {
        }
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
