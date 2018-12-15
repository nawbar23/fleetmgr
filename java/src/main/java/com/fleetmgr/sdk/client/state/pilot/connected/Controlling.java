package com.fleetmgr.sdk.client.state.pilot.connected;

import com.fleetmgr.interfaces.AddChannelsRequest;
import com.fleetmgr.interfaces.Role;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.CloseChannels;
import com.fleetmgr.sdk.client.event.input.user.OpenChannels;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.ChannelsClosed;
import com.fleetmgr.sdk.client.event.output.facade.FacadeEvent;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Controlling extends BaseState {

    Controlling(BaseState state) {
        super(state);
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        switch (event.getType()) {
            case OPEN_CHANNELS:
                OpenChannels openChannels = (OpenChannels) event;
                send(ClientMessage.newBuilder()
                        .setCommand(Command.ADD_CHANNELS)
                        .setRequestChannels(AddChannelsRequest.newBuilder()
                                .addAllChannelId(openChannels.getChannels())
                                .build())
                        .build());
                return Optional.empty();

            case CLOSE_CHANNELS:
                CloseChannels closeChannels = (CloseChannels) event;
                backend.closeChannels(closeChannels.getChannels());
                send(ClientMessage.newBuilder()
                        .setCommand(Command.REMOVE_CHANNELS)
                        .setRequestChannels(AddChannelsRequest.newBuilder()
                                .addAllChannelId(closeChannels.getChannels())
                                .build())
                        .build());
                return Optional.empty();

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
            case ADD_CHANNELS:
                if (message.getResponse() == Response.ACCEPTED) {
                    return Optional.of(new ValidatingChannels(this, Role.LEADER,
                            message.getRequestChannels().getChannelList()));

                } else {
                    return defaultUserEventHandler(message);
                }

            case REMOVE_CHANNELS:
                if (message.getResponse() == Response.ACCEPTED) {
                    listener.onEvent(new ChannelsClosed(null));
                    return Optional.empty();

                } else {
                    return defaultUserEventHandler(message);
                }

            case DEVICE_UNREACHABLE:
                listener.onEvent(new FacadeEvent(FacadeEvent.Type.DEVICE_UNREACHABLE));
                return Optional.empty();

            case RELEASE_CONTROL:
                return Optional.of(new ReleasingControl(this));

            default:
                return defaultUserEventHandler(message);
        }
    }

    @Override
    public String toString() {
        return "Controlling";
    }
}
