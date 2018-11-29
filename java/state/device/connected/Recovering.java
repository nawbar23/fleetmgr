package com.fleetmgr.java.sdk.state.device.connected;

import com.fleetmgr.java.sdk.event.input.connection.ConnectionEvent;
import com.fleetmgr.java.sdk.event.input.connection.Received;
import com.fleetmgr.java.sdk.event.input.user.UserEvent;
import com.fleetmgr.java.sdk.event.output.facade.FacadeEvent;
import com.fleetmgr.java.sdk.state.State;
import com.fleetmgr.interfaces.facade.control.ControlMessage;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.11.2018
 * Description:
 */
public class Recovering extends State {

    Recovering(State state) {
        super(state);
    }

    @Override
    public State start() {
        heartbeatHandler.end();
        listener.onEvent(new FacadeEvent(FacadeEvent.Type.CONNECTION_LOST));
        closeAllChannels();
        return null;
    }

    @Override
    public State notifyConnection(ConnectionEvent event) {
        switch (event.getType()) {
            case RECEIVED:
                return handleMessage(((Received)event).getMessage());

            default:
                return defaultEventHandle(event.toString());
        }
    }

    @Override
    public State notifyEvent(UserEvent event) {
        switch (event.getType()) {
            case RELEASE:
                return new Released(this);

            default:
                return defaultEventHandle(event.toString());
        }
    }

    private State handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            default:
                return defaultMessageHandle(message);
        }
    }

    @Override
    public String toString() {
        return "Recovering";
    }
}
