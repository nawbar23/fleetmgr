package com.fleetmgr.client.sdk.state.device;

import com.fleetmgr.client.sdk.event.input.connection.ConnectionEvent;
import com.fleetmgr.client.sdk.event.output.facade.FacadeEvent;
import com.fleetmgr.client.sdk.event.input.user.UserEvent;
import com.fleetmgr.client.sdk.state.State;
import com.fleetmgr.client.sdk.state.device.connected.Ready;
import com.fleetmgr.client.sdk.state.device.connected.Recovering;
import com.fleetmgr.client.sdk.state.device.connected.Released;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Connected extends State {

    private State internalState;

    Connected(State state) {
        super(state);
        this.internalState = new Ready(this);
    }

    @Override
    public State start() {
        internalState.start();
        heartbeatHandler.start();
        listener.onEvent(new FacadeEvent(FacadeEvent.Type.ATTACHED));
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
