package com.fleetmgr.sdk.client.state.device.connected;

import com.fleetmgr.interfaces.ChannelsResponse;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.ChannelsClosed;
import com.fleetmgr.sdk.client.event.output.facade.ChannelsOpened;
import com.fleetmgr.sdk.client.event.output.facade.FacadeEvent;
import com.fleetmgr.sdk.client.traffic.Channel;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Flying extends BaseState {

    private List<com.fleetmgr.interfaces.Channel> initialChannels;

    Flying(BaseState state, List<com.fleetmgr.interfaces.Channel> initialChannels) {
        super(state);
        this.initialChannels = initialChannels;
    }

    @Override
    public void start() {
        attachChannels(initialChannels);
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        switch (event.getType()) {
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
            case ATTACH_CHANNELS:
                attachChannels(message.getAttachChannels().getChannelsList());
                return Optional.empty();

            case RELEASE_CHANNELS:
                releaseChannels(
                        message.getChannels().getAttachedChannelsList(),
                        message.getCommand());
                return Optional.empty();

            case OPERATION_ENDED:
                releaseChannels(
                        new LinkedList<>(backend.getSockets().keySet()),
                        message.getCommand());
                listener.onEvent(new FacadeEvent(FacadeEvent.Type.OPERATION_ENDED));
                return Optional.of(new Ready(this));

            default:
                return defaultUserEventHandler(message);
        }
    }

    private void attachChannels(List<com.fleetmgr.interfaces.Channel> channels) {
        Map<Long, Channel> validated = backend.validateChannels(channels);
        listener.onEvent(new ChannelsOpened(validated.values()));
        send(ClientMessage.newBuilder()
                .setCommand(Command.ATTACH_CHANNELS)
                .setResponse(Response.ACCEPTED)
                .setAttachChannels(ChannelsResponse.newBuilder()
                        .addAllAttachedChannels(validated.keySet())
                        .build())
                .build());
    }

    private void releaseChannels(List<Long> channels, Command request) {
        listener.onEvent(new ChannelsClosed(channels));
        backend.closeChannels(channels);
        send(ClientMessage.newBuilder()
                .setCommand(request)
                .setResponse(Response.ACCEPTED)
                .setAttachChannels(ChannelsResponse.newBuilder()
                        .addAllAttachedChannels(channels)
                        .build())
                .build());
    }

    @Override
    public String toString() {
        return "Flying";
    }
}
