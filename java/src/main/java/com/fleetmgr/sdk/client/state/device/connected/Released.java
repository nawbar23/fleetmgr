package com.fleetmgr.sdk.client.state.device.connected;

import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 25.09.2018
 * Description:
 */
public class Released extends BaseState {


    Released(BaseState state) {
        super(state);
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        return defaultConnectionEventHandler(event.toString());
    }

    @Override
    public Optional<BaseState> onConnectionEvent(ConnectionEvent event) {
        return defaultConnectionEventHandler(event.toString());
    }

    @Override
    public String toString() {
        return "Released";
    }
}
