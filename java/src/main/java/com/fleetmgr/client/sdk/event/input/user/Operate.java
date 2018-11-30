package com.fleetmgr.client.sdk.event.input.user;

import java.util.Collection;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class Operate extends UserEvent {

    private long deviceRefId;
    private Collection<Long> channels;

    public Operate(long deviceRefId, Collection<Long> channels) {
        super(Type.OPERATE);
        this.deviceRefId = deviceRefId;
        this.channels = channels;
    }

    public long getDeviceRefId() {
        return deviceRefId;
    }

    public Collection<Long> getChannels() {
        return channels;
    }

    @Override
    public String toString() {
        return "Operate{" +
                "deviceRefId=" + deviceRefId +
                ", channels=" + channels +
                '}';
    }
}
