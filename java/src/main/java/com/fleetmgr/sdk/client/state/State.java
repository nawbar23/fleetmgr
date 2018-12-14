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

    public State(Client client,
                 ClientBackend backend,
                 Client.Listener listener) {
        this.client = client;
        this.backend = backend;
        this.listener = listener;
    }

    public State(State state) {
        this.client = state.client;
        this.listener = state.listener;
        this.backend = state.backend;
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

    protected abstract State notifyEvent(UserEvent event);

    protected abstract State notifyConnection(ConnectionEvent event);

    public void send(ClientMessage message) {
        backend.send(message);
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

    protected void trace(String message) {
        listener.trace(message);
    }
}
