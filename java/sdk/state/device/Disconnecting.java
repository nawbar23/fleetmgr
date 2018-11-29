package com.fleetmgr.java.sdk.state.device;

import com.fleetmgr.java.sdk.event.input.connection.ConnectionEvent;
import com.fleetmgr.java.sdk.event.output.facade.FacadeEvent;
import com.fleetmgr.java.sdk.event.input.user.UserEvent;
import com.fleetmgr.java.sdk.state.State;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Disconnecting extends State {

    private boolean wasRecovering;

    Disconnecting(State state) {
        super(state);
        this.wasRecovering = false;
    }

    Disconnecting(State state, boolean wasRecovering) {
        super(state);
        this.wasRecovering = wasRecovering;
    }

    @Override
    public State start() {
        heartbeatHandler.end();
        if (wasRecovering) {
            client.closeFacadeChannel();
            listener.onEvent(new FacadeEvent(FacadeEvent.Type.RELEASED));
            return new Disconnected(this);

        } else {
            return null;
        }
    }

    @Override
    public State notifyConnection(ConnectionEvent event) {
        switch (event.getType()) {
            case CLOSED:
                client.closeFacadeChannel();
                listener.onEvent(new FacadeEvent(FacadeEvent.Type.RELEASED));
                return new Disconnected(this);

            default:
                return defaultEventHandle(event.toString());
        }
    }

    @Override
    public State notifyEvent(UserEvent event) {
        switch (event.getType()) {
            default:
                return defaultEventHandle(event.toString());
        }
    }

    @Override
    public String toString() {
        return "Disconnecting";
    }
}
