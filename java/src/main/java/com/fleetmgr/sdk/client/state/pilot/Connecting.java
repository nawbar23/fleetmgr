package com.fleetmgr.sdk.client.state.pilot;

import com.fleetmgr.interfaces.AddChannelsRequest;
import com.fleetmgr.interfaces.OperateRequest;
import com.fleetmgr.interfaces.OperateResponse;
import com.fleetmgr.interfaces.Role;
import com.fleetmgr.interfaces.facade.control.*;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.io.IOException;
import java.util.Collection;
import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Connecting extends BaseState {

    private long deviceRefId;
    private Collection<Long> channels;

    private Role role;

    Connecting(BaseState state, long deviceRefId, Collection<Long> channels) {
        super(state);
        this.deviceRefId = deviceRefId;
        this.channels = channels;
    }

    @Override
    public void start() {
        try {
            OperateResponse operateResponse = backend.getCoreClient().operate(
                    OperateRequest.newBuilder()
                            .setRequestedDeviceId(deviceRefId)
                            .build());
            backend.openFacadeConnection(
                    operateResponse.getHost(),
                    operateResponse.getPort());
            role = operateResponse.getRole();
            send(ClientMessage.newBuilder()
                    .setCommand(Command.SETUP)
                    .setAttach(SetupRequest.newBuilder()
                            .setKey(operateResponse.getKey())
                            .build())
                    .setRequestChannels(AddChannelsRequest.newBuilder()
                            .addAllChannelId(channels)
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
                    return Optional.of(new Connected(this, role,
                            message.getRequestChannels().getChannelList()));

                } else {
                    return defaultUserEventHandler(message);
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
