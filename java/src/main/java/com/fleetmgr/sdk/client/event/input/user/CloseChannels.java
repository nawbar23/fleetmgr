package com.fleetmgr.sdk.client.event.input.user;

import java.util.List;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class CloseChannels extends UserEvent {

    private List<Long> channels;

    public CloseChannels(List<Long> channels) {
        super(Type.CLOSE_CHANNELS);
        this.channels = channels;
    }

    public List<Long> getChannels() {
        return channels;
    }

    @Override
    public String toString() {
        return "CloseChannels{" +
                "channels=" + channels +
                '}';
    }
}
