package com.fleetmgr.java.sdk.traffic;

import java.io.IOException;

public abstract class Channel {

    public interface Listener {
        void onReceived(Channel channel, byte[] data, int size);
        void onClosed(Channel channel);
        void trace(String message);
    }

    final long channelId;

    protected Listener listener;

    Channel(long channelId, Listener listener) {
        this.channelId = channelId;
        this.listener = listener;
    }

    public void setListener(Listener listener) {
        this.listener = listener;
    }

    public long getChannelId() {
        return channelId;
    }

    public abstract void send(byte[] data, int size) throws IOException;

    public abstract void close();

    protected void trace(String message) {
        listener.trace("[" + toString() + "]: " + message);
    }
}
