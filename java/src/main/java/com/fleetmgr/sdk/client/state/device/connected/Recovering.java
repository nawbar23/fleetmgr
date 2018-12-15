package com.fleetmgr.sdk.client.state.device.connected;

import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.FacadeEvent;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.11.2018
 * Description:
 */
public class Recovering extends BaseState {

    Recovering(BaseState state) {
        super(state);
    }

    @Override
    public void start() {
        backend.getHeartbeatHandler().end();
        listener.onEvent(new FacadeEvent(FacadeEvent.Type.CONNECTION_LOST));
        backend.closeAllChannels();
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        switch (event.getType()) {
            case RELEASE:
                return Optional.of(new Released(this));

            default:
                return defaultConnectionEventHandler(event.toString());
        }
    }

    @Override
    public Optional<BaseState> onConnectionEvent(ConnectionEvent event) {
        switch (event.getType()) {
            case RECEIVED:
                return handleMessage(((Received) event).getMessage());

            default:
                return defaultConnectionEventHandler(event.toString());
        }
    }

    private Optional<BaseState> handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            default:
                return defaultUserEventHandler(message);
        }
    }

    @Override
    public String toString() {
        return "Recovering";
    }
}
