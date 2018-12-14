package com.fleetmgr.sdk.client.state.pilot.connected;

import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.CloseChannels;
import com.fleetmgr.sdk.client.event.input.user.OpenChannels;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.ChannelsClosed;
import com.fleetmgr.sdk.client.event.output.facade.FacadeEvent;
import com.fleetmgr.sdk.client.state.State;
import com.fleetmgr.interfaces.AddChannelsRequest;
import com.fleetmgr.interfaces.Role;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Controlling extends State {

    Controlling(State state) {
        super(state);
    }

    @Override
    public State start() {
        return null;
    }

    @Override
    public State notifyEvent(UserEvent event) {
        switch (event.getType()) {
            case OPEN_CHANNELS:
                OpenChannels openChannels = (OpenChannels)event;
                send(ClientMessage.newBuilder()
                        .setCommand(Command.ADD_CHANNELS)
                        .setRequestChannels(AddChannelsRequest.newBuilder()
                                .addAllChannelId(openChannels.getChannels())
                                .build())
                        .build());
                return null;

            case CLOSE_CHANNELS:
                CloseChannels closeChannels = (CloseChannels)event;
                backend.closeChannels(closeChannels.getChannels());
                send(ClientMessage.newBuilder()
                        .setCommand(Command.REMOVE_CHANNELS)
                        .setRequestChannels(AddChannelsRequest.newBuilder()
                                .addAllChannelId(closeChannels.getChannels())
                                .build())
                        .build());
                return null;

            case RELEASE:
                return new Releasing(this);

            default:
                return defaultEventHandle(event.toString());
        }
    }

    @Override
    public State notifyConnection(ConnectionEvent event) {
        switch (event.getType()) {
            case RECEIVED:
                return handleMessage(((Received) event).getMessage());

            case LOST:
                return new Recovering(this);

            default:
                return defaultEventHandle(event.toString());
        }
    }

    private State handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            case ADD_CHANNELS:
                if (message.getResponse() == Response.ACCEPTED) {
                    return new ValidatingChannels(this, Role.LEADER,
                            message.getRequestChannels().getChannelList());

                } else {
                    return defaultMessageHandle(message);
                }

            case REMOVE_CHANNELS:
                if (message.getResponse() == Response.ACCEPTED) {
                    listener.onEvent(new ChannelsClosed(null));
                    return null;

                } else {
                    return defaultMessageHandle(message);
                }

            case DEVICE_UNREACHABLE:
                listener.onEvent(new FacadeEvent(FacadeEvent.Type.DEVICE_UNREACHABLE));
                return null;

            case RELEASE_CONTROL:
                return new ReleasingControl(this);

            default:
                return defaultMessageHandle(message);
        }
    }

    @Override
    public String toString() {
        return "Controlling";
    }
}
