package com.fleetmgr.java.sdk.state.device.connected;

import com.fleetmgr.java.sdk.event.input.connection.ConnectionEvent;
import com.fleetmgr.java.sdk.event.input.connection.Received;
import com.fleetmgr.java.sdk.event.input.user.UserEvent;
import com.fleetmgr.java.sdk.state.State;
import com.fleetmgr.interfaces.facade.control.ControlMessage;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Ready extends State {

    public Ready(State state) {
        super(state);
    }

    @Override
    public State start() {
        return null;
    }

    @Override
    public State notifyConnection(ConnectionEvent event) {
        switch (event.getType()) {
            case RECEIVED:
                return handleMessage(((Received)event).getMessage());

            case LOST:
                return new Recovering(this);

            default:
                return defaultEventHandle(event.toString());
        }
    }

    @Override
    public State notifyEvent(UserEvent event) {
        switch (event.getType()) {
            case RELEASE:
                return new Releasing(this);

            default:
                return defaultEventHandle(event.toString());
        }
    }

    private State handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            case ATTACH_CHANNELS:
                return new Flying(this, message.getAttachChannels().getChannelsList());

            default:
                return defaultMessageHandle(message);
        }
    }

    @Override
    public String toString() {
        return "Ready";
    }
}
