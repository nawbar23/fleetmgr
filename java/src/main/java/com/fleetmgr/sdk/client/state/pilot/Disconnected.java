package com.fleetmgr.sdk.client.state.pilot;

import com.fleetmgr.sdk.client.Client;
import com.fleetmgr.sdk.client.backend.ClientBackend;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.user.Operate;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.state.State;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Disconnected extends State {

    public Disconnected(Client client,
                        ClientBackend backend,
                        Client.Listener listener) {
        super(client, backend, listener);
    }

    Disconnected(State state) {
        super(state);
    }

    @Override
    public State start() {
        return null;
    }

    @Override
    public State notifyEvent(UserEvent event) {
        switch (event.getType()) {
            case OPERATE:
                Operate operate = (Operate)event;
                return new Connecting(this,
                        operate.getDeviceId(),
                        operate.getChannels());

            default:
                return defaultEventHandle(event.toString());
        }
    }

    @Override
    public State notifyConnection(ConnectionEvent event) {
        return defaultEventHandle(event.toString());
    }

    @Override
    public String toString() {
        return "Disconnected";
    }
}
