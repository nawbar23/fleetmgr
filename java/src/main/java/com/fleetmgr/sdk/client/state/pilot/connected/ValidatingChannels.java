package com.fleetmgr.sdk.client.state.pilot.connected;

import com.fleetmgr.interfaces.ChannelIndicationList;
import com.fleetmgr.interfaces.ChannelResponse;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.traffic.Channel;
import com.fleetmgr.sdk.client.traffic.ChannelImpl;
import com.fleetmgr.sdk.client.event.output.facade.ChannelsOpened;
import com.fleetmgr.sdk.client.state.State;
import com.fleetmgr.interfaces.Role;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;

import java.util.Collection;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 * Created by: Bartosz Nawrot
 * Date: 24.09.2018
 * Description:
 */
public class ValidatingChannels extends State {

    private Role role;
    private List<ChannelResponse> channels;

    private Map<Long, Channel> validated;

    public ValidatingChannels(State state, Role role, List<ChannelResponse> channels) {
        super(state);
        this.role = role;
        this.channels = channels;
    }

    @Override
    public State start() {
        validated = backend.getChannelsHandler().validateChannels(channels);
        send(ClientMessage.newBuilder()
                .setCommand(Command.CHANNELS_READY)
                .setChannelsIndication(ChannelIndicationList.newBuilder()
                        .addAllIds(validated.keySet())
                        .build())
                .build());
        return null;
    }

    @Override
    public State notifyEvent(UserEvent event) {
        switch (event.getType()) {
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

            default:
                return defaultEventHandle(event.toString());
        }
    }

    private State handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            case CHANNELS_READY:
                if (message.getResponse() == Response.ACCEPTED) {
                    listener.onEvent(new ChannelsOpened(new LinkedList<>(validated.values())));
                    switch (role) {
                        case LEADER:
                            return new Controlling(this);
                        case PILOT:
                            return new Spectating(this);
                    }

                } else {
                    return defaultMessageHandle(message);
                }

            default:
                return defaultMessageHandle(message);
        }
    }

    @Override
    public String toString() {
        return "ValidatingChannels";
    }
}
