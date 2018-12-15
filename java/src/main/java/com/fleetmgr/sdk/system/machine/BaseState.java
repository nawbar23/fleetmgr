package com.fleetmgr.sdk.system.machine;

import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.sdk.client.Client;
import com.fleetmgr.sdk.client.backend.ClientBackend;
import com.fleetmgr.sdk.client.event.input.Event;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.traffic.Channel;

import java.util.Optional;
import java.util.logging.Logger;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public abstract class BaseState {

    private static final Logger logger = Logger.getLogger(BaseState.class.getName());

    protected Client client;
    protected Client.Listener listener;

    protected ClientBackend backend;

    public BaseState(BaseState state) {
        this.client = state.client;
        this.listener = state.listener;
        this.backend = state.backend;
    }

    public BaseState(Client client, ClientBackend backend, Client.Listener listener) {
        this.client = client;
        this.backend = backend;
        this.listener = listener;
    }

    public void start() {
    }

    public Optional<BaseState> getInitialState() {
        return Optional.empty();
    }

    protected abstract Optional<BaseState> onUserEvent(UserEvent event);

    protected abstract Optional<BaseState> onConnectionEvent(ConnectionEvent event);

    public Optional<BaseState> handleEvent(Event event) {
        if (event instanceof ConnectionEvent) {
            return onConnectionEvent((ConnectionEvent) event);

        } else if (event instanceof UserEvent) {
            return onUserEvent((UserEvent) event);

        } else {
            logger.warning("Unexpected event type");
            return Optional.empty();
        }
    }

    public void send(ClientMessage message) {
        backend.send(message);
    }

    protected Optional<BaseState> defaultConnectionEventHandler(String eventName) {
        logger.warning("Unexpected: " + eventName + " @ " + toString());
        return Optional.empty();
    }

    protected Optional<BaseState> defaultUserEventHandler(ControlMessage message) {

        if (message.getCommand() == Command.HEARTBEAT && message.hasHeartbeat()) {
            backend.getHeartbeatHandler().handleHeartbeat(message);

        } else {
            logger.warning("Unexpected ControlMessage received:\n" + message + " @ " + toString());
        }
        return Optional.empty();
    }
}
