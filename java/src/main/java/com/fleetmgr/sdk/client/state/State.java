package com.fleetmgr.sdk.client.state;

import com.fleetmgr.sdk.client.Client;
import com.fleetmgr.sdk.client.backend.ClientBackend;
import com.fleetmgr.sdk.client.backend.HeartbeatHandler;
import com.fleetmgr.sdk.client.core.CoreClient;
import com.fleetmgr.sdk.client.event.input.Event;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.traffic.Channel;
import com.fleetmgr.sdk.client.traffic.UdpChannel;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;

import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ExecutorService;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public abstract class State implements
        com.fleetmgr.sdk.system.machine.State<Event> {

    protected Client client;
    protected Client.Listener listener;

    protected ClientBackend backend;

    private ExecutorService executor;
    protected HashMap<Long, Channel> sockets;

    protected CoreClient coreClient;

    public State(Client client,
                 ClientBackend backend,
                 CoreClient coreClient,
                 Client.Listener listener,
                 ExecutorService executor) {
        this.client = client;
        this.coreClient = coreClient;
        this.backend = backend;
        this.listener = listener;
        this.executor = executor;

        this.sockets = new HashMap<>();
    }

    public State(State state) {
        this.client = state.client;
        this.listener = state.listener;
        this.backend = state.backend;
        this.coreClient = state.coreClient;
        this.executor = state.executor;
        this.sockets = state.sockets;
    }

    @Override
    public State handleEvent(Event event) {
        if (event instanceof ConnectionEvent) {
            return notifyConnection((ConnectionEvent)event);

        } else if (event instanceof UserEvent) {
            return notifyEvent((UserEvent)event);

        } else {
            trace("Unexpected event type");
            return null;
        }
    }

    protected abstract State notifyConnection(ConnectionEvent event);

    protected abstract State notifyEvent(UserEvent event);

    public void send(ClientMessage message) {
        backend.send(message);
    }

    protected Map<Long, Channel> validateChannels(Collection<com.fleetmgr.interfaces.Channel> channels) {
        Map<Long, Channel> opened = new HashMap<>();
        for (com.fleetmgr.interfaces.Channel c : channels) {
            try {
                trace("Opening channel id: " + c.getId());
                UdpChannel socket = new UdpChannel(executor,
                        c.getIp(), c.getPort(), c.getId(), createDefaultSocketListener());
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

    protected void closeChannels(Collection<Long> channels) {
        for (Long c : channels) {
            trace("Closing channel id: " + c);
            Channel s = sockets.remove(c);
            if (s != null) {
                s.close();
            }
        }
    }

    protected void closeAllChannels() {
        for (Channel s : sockets.values()) {
            trace("Closing channel id: " + s.getChannelId());
            s.close();
        }
        sockets.clear();
    }

    protected State defaultEventHandle(String eventName) {
        trace("Unexpected: " + eventName + " @ " + toString());
        return null;
    }

    protected State defaultMessageHandle(ControlMessage message) {
        if (message.getCommand() == Command.HEARTBEAT && message.hasHeartbeat()) {
            backend.getHeartbeatHandler().handleHeartbeat(message);

        } else {
            trace("Unexpected ControlMessage received:\n" + message + " @ " + toString());
        }
        return null;
    }

    private Channel.Listener createDefaultSocketListener() {
        return new Channel.Listener() {
            @Override
            public void onReceived(Channel channel, byte[] data, int size) {
            }

            @Override
            public void onClosed(Channel channel) {
            }

            @Override
            public void trace(String message) {
            }
        };
    }

    protected void trace(String message) {
        listener.trace(message);
    }
}
