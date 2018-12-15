package com.fleetmgr.sdk.client.state.device.connected;

import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Ready extends BaseState {

    public Ready(BaseState state) {
        super(state);
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        switch (event.getType()) {
            case RELEASE:
                return Optional.of(new Releasing(this));

            default:
                return defaultConnectionEventHandler(event.toString());
        }
    }

    @Override
    public Optional<BaseState> onConnectionEvent(ConnectionEvent event) {
        switch (event.getType()) {
            case RECEIVED:
                return handleMessage(((Received) event).getMessage());

            case LOST:
                return Optional.of(new Recovering(this));

            default:
                return defaultConnectionEventHandler(event.toString());
        }
    }

    private Optional<BaseState> handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            case ATTACH_CHANNELS:
                return Optional.of(new Flying(this, message.getAttachChannels().getChannelsList()));

            default:
                return defaultUserEventHandler(message);
        }
    }

    @Override
    public String toString() {
        return "Ready";
    }
}
