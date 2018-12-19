package com.fleetmgr.sdk.client.event.input.user;

import com.fleetmgr.interfaces.ChannelRequest;

import java.util.List;


/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class OpenChannels extends UserEvent {

    private List<ChannelRequest> channels;

    public OpenChannels(List<ChannelRequest> channels) {
        super(Type.OPEN_CHANNELS);
        this.channels = channels;
    }

    public List<ChannelRequest> getChannels() {
        return channels;
    }

    @Override
    public String toString() {
        return "OpenChannels{" +
                "channels=" + channels +
                '}';
    }
}
