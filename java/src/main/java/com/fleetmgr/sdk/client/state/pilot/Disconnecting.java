package com.fleetmgr.sdk.client.state.pilot;

import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.FacadeEvent;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Disconnecting extends BaseState {

    private boolean wasRecovering;

    Disconnecting(BaseState state, boolean wasRecovering) {
        super(state);
        this.wasRecovering = wasRecovering;
    }

    @Override
    public void start() {
        backend.getHeartbeatHandler().end();

        if (wasRecovering) {
            backend.closeFacadeChannel();
            listener.onEvent(new FacadeEvent(FacadeEvent.Type.RELEASED));
        }
    }

    @Override
    public Optional<BaseState> getInitialState() {
        if (wasRecovering) {
            return Optional.of(new Disconnected(this));
        } else {
            return Optional.empty();
        }
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        switch (event.getType()) {
            default:
                return defaultConnectionEventHandler(event.toString());
        }
    }

    @Override
    public Optional<BaseState> onConnectionEvent(ConnectionEvent event) {
        switch (event.getType()) {
            case CLOSED:
                backend.closeFacadeChannel();
                listener.onEvent(new FacadeEvent(FacadeEvent.Type.RELEASED));
                return Optional.of(new Disconnected(this));

            default:
                return defaultConnectionEventHandler(event.toString());
        }
    }

    @Override
    public String toString() {
        return "Disconnecting";
    }
}
