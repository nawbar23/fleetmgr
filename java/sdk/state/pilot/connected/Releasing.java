package com.fleetmgr.client.sdk.state.pilot.connected;

import com.fleetmgr.client.sdk.event.input.connection.ConnectionEvent;
import com.fleetmgr.client.sdk.event.input.connection.Received;
import com.fleetmgr.client.sdk.event.input.user.UserEvent;
import com.fleetmgr.client.sdk.state.State;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;

/**
 * Created by: Bartosz Nawrot
 * Date: 24.09.2018
 * Description:
 */
public class Releasing extends State {

    Releasing(State state) {
        super(state);
    }

    @Override
    public State start() {
        closeAllChannels();
        send(ClientMessage.newBuilder()
                .setCommand(Command.RELEASE)
                .build());
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
        return defaultEventHandle(event.toString());
    }

    private State handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            case RELEASE:
                if (message.getResponse() == Response.ACCEPTED) {
                    return new Released(this);

                } else {
                    return defaultMessageHandle(message);
                }

            case HEARTBEAT:
                trace("Heartbeat ignored during release procedure");
                return null;

            default:
                return defaultMessageHandle(message);
        }
    }

    @Override
    public String toString() {
        return "Releasing";
    }
}
