package com.fleetmgr.client.sdk.event.output.facade;

import java.util.Collection;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class ChannelsClosed extends FacadeEvent {

    private Collection<Long> sockets;

    public ChannelsClosed(Collection<Long> sockets) {
        super(Type.CHANNELS_CLOSED);
        this.sockets = sockets;
    }

    public ChannelsClosed(Type type, Collection<Long> sockets) {
        super(type);
        this.sockets = sockets;
    }

    public Collection<Long> getSockets() {
        return sockets;
    }

    @Override
    public String toString() {
        return "ChannelsClosed{" +
                "sockets=" + sockets +
                '}';
    }
}
