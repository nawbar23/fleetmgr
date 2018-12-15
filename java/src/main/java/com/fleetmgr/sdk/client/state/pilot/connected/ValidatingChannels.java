package com.fleetmgr.sdk.client.state.pilot.connected;

import com.fleetmgr.interfaces.ChannelsResponse;
import com.fleetmgr.interfaces.Role;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.ChannelsOpened;
import com.fleetmgr.sdk.client.traffic.Channel;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Collection;
import java.util.Map;
import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 24.09.2018
 * Description:
 */
public class ValidatingChannels extends BaseState {

    private Role role;
    private Collection<com.fleetmgr.interfaces.Channel> channels;

    private Map<Long, Channel> validated;

    public ValidatingChannels(BaseState state, Role role, Collection<com.fleetmgr.interfaces.Channel> channels) {
        super(state);
        this.role = role;
        this.channels = channels;
    }

    @Override
    public void start() {
        validated = backend.validateChannels(channels);
        send(ClientMessage.newBuilder()
                .setCommand(Command.CHANNELS_READY)
                .setAttachChannels(ChannelsResponse.newBuilder()
                        .addAllAttachedChannels(validated.keySet())
                        .build())
                .build());
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        switch (event.getType()) {
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

            default:
                return defaultConnectionEventHandler(event.toString());
        }
    }

    private Optional<BaseState> handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            case CHANNELS_READY:
                if (message.getResponse() == Response.ACCEPTED) {
                    listener.onEvent(new ChannelsOpened(validated.values()));
                    switch (role) {
                        case LEADER:
                            return Optional.of(new Controlling(this));
                        case PILOT:
                            return Optional.of(new Spectating(this));
                    }

                } else {
                    return defaultUserEventHandler(message);
                }

            default:
                return defaultUserEventHandler(message);
        }
    }

    @Override
    public String toString() {
        return "ValidatingChannels";
    }
}
