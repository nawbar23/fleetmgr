package com.fleetmgr.java.sdk.state.device.connected;

import com.fleetmgr.java.sdk.event.input.connection.ConnectionEvent;
import com.fleetmgr.java.sdk.event.input.user.UserEvent;
import com.fleetmgr.java.sdk.state.State;

/**
 * Created by: Bartosz Nawrot
 * Date: 25.09.2018
 * Description:
 */
public class Released extends State {


    Released(State state) {
        super(state);
    }

    @Override
    public State start() {
        return null;
    }

    @Override
    public State notifyConnection(ConnectionEvent event) {
        return defaultEventHandle(event.toString());
    }

    @Override
    public State notifyEvent(UserEvent event) {
        return defaultEventHandle(event.toString());
    }


    @Override
    public String toString() {
        return "Released";
    }
}
