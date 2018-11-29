package com.fleetmgr.java.sdk.state.pilot;

import com.fleetmgr.java.sdk.Client;
import com.fleetmgr.java.sdk.core.CoreClient;
import com.fleetmgr.java.sdk.event.input.connection.ConnectionEvent;
import com.fleetmgr.java.sdk.event.input.user.Operate;
import com.fleetmgr.java.sdk.event.input.user.UserEvent;
import com.fleetmgr.java.sdk.state.State;

import java.util.concurrent.ExecutorService;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Disconnected extends State {

    public Disconnected(String key,
                        Client client,
                        CoreClient coreClient,
                        Client.Listener listener,
                        ExecutorService executor) {
        super(key, client, coreClient, listener, executor);
    }

    Disconnected(State state) {
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
        switch (event.getType()) {
            case OPERATE:
                Operate operate = (Operate)event;
                return new Connecting(this,
                        operate.getDeviceRefId(),
                        operate.getChannels());

            default:
                return defaultEventHandle(event.toString());
        }
    }

    @Override
    public String toString() {
        return "Disconnected";
    }
}
