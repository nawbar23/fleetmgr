package com.fleetmgr.client.sdk.state.device;

import com.fleetmgr.client.sdk.event.input.connection.ConnectionEvent;
import com.fleetmgr.client.sdk.event.input.connection.Received;
import com.fleetmgr.client.sdk.event.output.facade.Error;
import com.fleetmgr.client.sdk.event.input.user.UserEvent;
import com.fleetmgr.client.sdk.state.State;
import com.fleetmgr.interfaces.AttachResponse;
import com.fleetmgr.interfaces.facade.control.*;

import java.io.IOException;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Connecting extends State {

    Connecting(State state) {
        super(state);
    }

    @Override
    public State start() {
        try {
            AttachResponse attachResponse = coreClient.attach();
            client.openFacadeConnection(
                    attachResponse.getHost(),
                    attachResponse.getPort());
            send(ClientMessage.newBuilder()
                    .setCommand(Command.SETUP)
                    .setAttach(SetupRequest.newBuilder()
                            .setKey(attachResponse.getKey())
                            .build())
                    .build());
        } catch (IOException e) {
            e.printStackTrace();
        }
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
            case SETUP:
                if (message.getResponse() == Response.ACCEPTED) {
                    return new Connected(this);

                } else {
                    listener.onEvent(new Error(message.getMessage()));
                    return new Disconnecting(this);
                }
                
            default:
                return defaultMessageHandle(message);
        }
    }

    @Override
    public String toString() {
        return "Connecting";
    }
}
