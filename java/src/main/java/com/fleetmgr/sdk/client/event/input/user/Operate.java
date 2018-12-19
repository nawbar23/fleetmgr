package com.fleetmgr.sdk.client.event.input.user;

import com.fleetmgr.interfaces.ChannelRequest;

import java.util.List;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class Operate extends UserEvent {

    private long deviceId;

    private List<ChannelRequest> channels;

    public Operate(long deviceId, List<ChannelRequest> channels) {
        super(Type.OPERATE);
        this.deviceId = deviceId;
        this.channels = channels;
    }

    public long getDeviceId() {
        return deviceId;
    }

    public List<ChannelRequest> getChannels() {
        return channels;
    }

    @Override
    public String toString() {
        return "Operate{" +
                "deviceId=" + deviceId +
                ", channels=" + channels +
                '}';
    }
}
