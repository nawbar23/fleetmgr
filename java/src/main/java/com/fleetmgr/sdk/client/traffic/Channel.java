package com.fleetmgr.sdk.client.traffic;

import com.fleetmgr.sdk.client.core.https.HttpsClient;

import java.io.IOException;
import java.util.logging.Logger;

public abstract class Channel {

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

    public interface Listener {
        void onReceived(Channel channel, byte[] data, int size);

        void onClosed(Channel channel);
    }
}
