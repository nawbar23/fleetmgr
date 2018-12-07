package com.fleetmgr.sdk.client;

import com.fleetmgr.sdk.client.backend.ClientBackend;
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
public abstract class Client extends StateMachine<Event> {

    public interface Listener {
        Location getLocation();
        void onEvent(FacadeEvent event);
        void trace(String message);
    }

    private Listener listener;

    protected ClientBackend backend;

    CoreClient coreClient;

    Client(String coreAddress, String key, Listener listener, ExecutorService executor) {
        super(executor, null);
        this.listener = listener;

        this.coreClient = new CoreClient(coreAddress, key);

        this.backend = new ClientBackend(this::trace, this, listener, executor, coreClient);
    }

    @Override
    public void trace(String message) {
        listener.trace(message);
    }
}
