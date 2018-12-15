package com.fleetmgr.sdk.client.state.device;

import com.fleetmgr.sdk.client.Client;
import com.fleetmgr.sdk.client.backend.ClientBackend;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Disconnected extends BaseState {

    public Disconnected(Client client,
                        ClientBackend backend,
                        Client.Listener listener) {
        super(client, backend, listener);
    }

    Disconnected(BaseState state) {
        super(state);
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        switch (event.getType()) {
            case ATTACH:
                return Optional.of(new Connecting(this));

            default:
                return defaultConnectionEventHandler(event.toString());
        }
    }

    @Override
    public Optional<BaseState> onConnectionEvent(ConnectionEvent event) {
        return defaultConnectionEventHandler(event.toString());
    }

    @Override
    public String toString() {
        return "Disconnected";
    }
}
