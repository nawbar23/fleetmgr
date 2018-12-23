package com.fleetmgr.sdk.client.state.pilot.connected;

import com.fleetmgr.interfaces.ChannelIndicationList;
import com.fleetmgr.interfaces.ChannelRequestList;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.CloseChannels;
import com.fleetmgr.sdk.client.event.input.user.OpenChannels;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.ChannelsClosing;
import com.fleetmgr.sdk.client.event.output.facade.FacadeEvent;
import com.fleetmgr.sdk.client.state.State;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Operating extends State {

    Operating(State state) {
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
                        .setChannelsRequest(ChannelRequestList.newBuilder()
                                .addAllChannels(openChannels.getChannels())
                                .build())
                        .build());
                return null;

            case CLOSE_CHANNELS:
                CloseChannels closeChannels = (CloseChannels)event;
                backend.getChannelsHandler().closeChannels(closeChannels.getChannels());
                send(ClientMessage.newBuilder()
                        .setCommand(Command.REMOVE_CHANNELS)
                        .setChannelsIndication(ChannelIndicationList.newBuilder()
                                .addAllIds(closeChannels.getChannels())
                                .build())
                        .build());
                return null;

            case REQUEST_CONTROL:
                return new RequestingControl(this);

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
                    return new ValidatingChannels(this,
                            message.getChannelsResponse().getChannelsList());

                } else {
                    return defaultMessageHandle(message);
                }

            case REMOVE_CHANNELS:
                if (message.getResponse() == Response.ACCEPTED) {
                    listener.onEvent(new FacadeEvent(FacadeEvent.Type.CHANNELS_CLOSED));
                    return null;

                } else {
                    return defaultMessageHandle(message);
                }

            case OPERATION_UPDATED:
                listener.onEvent(new FacadeEvent(FacadeEvent.Type.OPERATION_UPDATED));
                return null;

            case RELEASE_CONTROL:
                return new ReleasingControl(this);

            case OPERATION_ENDED:
                listener.onEvent(new ChannelsClosing(backend.getChannelsHandler().getChannels()));
                backend.getChannelsHandler().closeAllChannels();
                send(ClientMessage.newBuilder()
                        .setCommand(Command.OPERATION_ENDED)
                        .setResponse(Response.ACCEPTED)
                        .build());
                return new Released(this);

            default:
                return defaultMessageHandle(message);
        }
    }

    @Override
    public String toString() {
        return "Operating";
    }
}
