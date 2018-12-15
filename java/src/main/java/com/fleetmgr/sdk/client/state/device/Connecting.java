package com.fleetmgr.sdk.client.state.device;

import com.fleetmgr.interfaces.AttachResponse;
import com.fleetmgr.interfaces.facade.control.*;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.Error;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.io.IOException;
import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Connecting extends BaseState {

    Connecting(BaseState state) {
        super(state);
    }

    @Override
    public void start() {
        try {
            AttachResponse attachResponse = backend.getCoreClient().attach();
            backend.openFacadeConnection(
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
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        return defaultConnectionEventHandler(event.toString());
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
            case SETUP:
                if (message.getResponse() == Response.ACCEPTED) {
                    return Optional.of(new Connected(this));

                } else {
                    listener.onEvent(new Error(message.getMessage()));
                    return Optional.of(new Disconnecting(this));
                }

            default:
                return defaultUserEventHandler(message);
        }
    }

    @Override
    public String toString() {
        return "Connecting";
    }
}
