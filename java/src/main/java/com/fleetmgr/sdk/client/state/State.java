package com.fleetmgr.sdk.client.state;

import java.util.logging.Level;
import com.fleetmgr.interfaces.facade.control.Response;
import com.fleetmgr.sdk.client.Client;
import com.fleetmgr.sdk.client.backend.ClientBackend;
import com.fleetmgr.sdk.client.event.input.Event;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;

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
            log(Level.INFO, "Unexpected event type");
            return null;
        }
    }

    protected abstract State notifyEvent(UserEvent event);

    protected abstract State notifyConnection(ConnectionEvent event);

    public void send(ClientMessage message) {
        backend.send(message);
    }

    protected State defaultEventHandle(String eventName) {
        log(Level.INFO, "Unexpected: " + eventName + " @ " + toString());
        return null;
    }

    protected State defaultMessageHandle(ControlMessage message) {
        if (isProcedureInitiation(message)) {
            // Incoming procedure initiation from the Facade has to be deferred
            // because it is possible to have collision - both Facade and User
            // can request procedure at the same time.
            // Then Facade will reject User request and SM will be moved
            // to Operating state, where recall has to be called.
            client.defer(new Received(message));

        } else if (message.getCommand() == Command.HEARTBEAT && message.hasHeartbeat()) {
            backend.getHeartbeatHandler().handleHeartbeat(message);

        } else {
            log(Level.INFO, "Unexpected ControlMessage received:\n" + message + " @ " + toString());
        }
        return null;
    }

    private boolean isProcedureInitiation(ControlMessage message) {
        return message.getResponse() == Response.UNDEFINED_RSP &&
                (message.getCommand() == Command.RELEASE_CONTROL ||
                        message.getCommand() == Command.RELEASE);
    }

    protected void log(Level level, String message) {
        listener.log(level, message);
    }
}
