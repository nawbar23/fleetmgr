package com.fleetmgr.java.sdk.event.input.user;

import java.util.Collection;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class OpenChannels extends UserEvent {

    private Collection<Long> channels;

    public OpenChannels(Collection<Long> channels) {
        super(Type.OPEN_CHANNELS);
        this.channels = channels;
    }

    public Collection<Long> getChannels() {
        return channels;
    }

    @Override
    public String toString() {
        return "OpenChannels{" +
                "channels=" + channels +
                '}';
    }
}
