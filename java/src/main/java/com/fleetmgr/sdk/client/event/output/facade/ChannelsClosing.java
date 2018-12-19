package com.fleetmgr.sdk.client.event.output.facade;

import com.fleetmgr.sdk.client.traffic.Channel;

import java.util.List;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class ChannelsClosing extends FacadeEvent {

    private List<Channel> channels;

    public ChannelsClosing(List<Channel> channels) {
        super(Type.CHANNELS_CLOSING);
        this.channels = channels;
    }

    public List<Channel> getChannels() {
        return channels;
    }

    @Override
    public String toString() {
        return "ChannelsClosing{" +
                "channels=" + channels +
                '}';
    }
}
