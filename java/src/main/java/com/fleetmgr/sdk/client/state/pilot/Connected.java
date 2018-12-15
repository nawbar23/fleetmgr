package com.fleetmgr.sdk.client.state.pilot;

import com.fleetmgr.interfaces.Channel;
import com.fleetmgr.interfaces.Role;
import com.fleetmgr.sdk.client.event.input.Event;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.OperationStarted;
import com.fleetmgr.sdk.client.state.pilot.connected.ValidatingChannels;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Collection;
import java.util.Optional;
import java.util.logging.Logger;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Connected extends BaseState {

    private static final Logger logger = Logger.getLogger(Connected.class.getName());

    private BaseState internalState;

    private Role initialRole;

    Connected(BaseState state, Role role, Collection<Channel> channels) {
        super(state);
        this.internalState = new ValidatingChannels(this, role, channels);
        this.initialRole = role;
    }

    @Override
    public void start() {
        internalState.start();
        backend.getHeartbeatHandler().start();
        listener.onEvent(new OperationStarted(initialRole));
        initialRole = null;
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        return handle(event);
    }

    @Override
    public Optional<BaseState> onConnectionEvent(ConnectionEvent event) {
        return handle(event);
    }

    private Optional<BaseState> handle(Event event) {
        Optional<BaseState> newState = internalState.handleEvent(event);
        boolean wasRecovering = internalState instanceof com.fleetmgr.sdk.client.state.device.connected.Recovering;

        while (newState.isPresent()) {
            logger.info("Connected transition: " + toString() + " -> Connected." + newState.toString());
            internalState = newState.get();

            internalState.start();
            newState = internalState.getInitialState();
        }

        if (internalState instanceof com.fleetmgr.sdk.client.state.device.connected.Released) {
            return Optional.of(new Disconnecting(this, wasRecovering));
        }

        return Optional.empty();
    }

    @Override
    public String toString() {
        return "Connected." + internalState;
    }
}
