package com.fleetmgr.sdk.client.state.pilot;

import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.state.pilot.connected.Recovering;
import com.fleetmgr.sdk.client.state.pilot.connected.Released;
import com.fleetmgr.sdk.client.state.pilot.connected.ValidatingChannels;
import com.fleetmgr.sdk.client.event.output.facade.OperationStarted;
import com.fleetmgr.sdk.client.state.State;
import com.fleetmgr.interfaces.Channel;
import com.fleetmgr.interfaces.Role;

import java.util.Collection;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Connected extends State {

    private State internalState;

    private Role initialRole;

    Connected(State state, Role role, Collection<Channel> channels) {
        super(state);
        this.internalState = new ValidatingChannels(this, role, channels);
        this.initialRole = role;
    }

    @Override
    public State start() {
        internalState.start();
        heartbeatHandler.start();
        listener.onEvent(new OperationStarted(initialRole));
        initialRole = null;
        return null;
    }

    @Override
    public State notifyConnection(ConnectionEvent event) {
        return onNewState(internalState.handleEvent(event));
    }

    @Override
    public State notifyEvent(UserEvent event) {
        return onNewState(internalState.handleEvent(event));
    }

    private State onNewState(State newState) {
        boolean wasRecovering = internalState instanceof Recovering;
        if (newState != null) {
            trace("Connected transition: " + toString() + " -> Connected." + newState.toString());
            internalState = newState;
            internalState.start();
        }
        if (internalState instanceof Released) {
            return new Disconnecting(this, wasRecovering);
        }
        return null;
    }

    @Override
    public String toString() {
        return "Connected." + internalState;
    }
}
