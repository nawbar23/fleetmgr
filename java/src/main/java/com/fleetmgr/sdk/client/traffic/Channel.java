package com.fleetmgr.sdk.client.traffic;

import com.fleetmgr.interfaces.Result;
import com.fleetmgr.interfaces.ValidateChannelRequest;
import com.fleetmgr.interfaces.ValidateChannelResponse;
import com.fleetmgr.sdk.client.traffic.socket.Socket;

import java.io.IOException;
import java.nio.ByteBuffer;

public class Channel implements Socket.Listener {

    public interface Listener {
        void onReceived(Channel channel, byte[] data, int size);
        void onClosed(Channel channel);
        void trace(String message);
    }

    private final long channelId;
    private final Socket socket;

    protected Listener listener;

    public Channel(long channelId, Socket socket) {
        this.channelId = channelId;
        this.socket = socket;
        this.listener = null;
    }

    public void setListener(Listener listener) {
        this.listener = listener;
    }

    public void open(String ip, int port, String key) throws IOException {
        socket.setListener(this);
        socket.connect(ip, port);

        ValidateChannelRequest validateChannelRequest = ValidateChannelRequest.newBuilder()
                .setKey(key)
                .build();

        socket.send(validateChannelRequest.toByteArray(), validateChannelRequest.getSerializedSize());

        byte[] buffer = new byte[256];
        int received = socket.readBlocking(buffer);

        ByteBuffer byteBuffer = ByteBuffer.wrap(buffer, 0, received);
        ValidateChannelResponse response = ValidateChannelResponse.parseFrom(byteBuffer);
        if (response.getResult() != Result.VALIDATION_ACCEPTED) {
            throw new IOException("Channel validation rejected");
        }

        socket.startReading();
    }

    public void close() {
        socket.disconnect();
    }

    public void send(byte[] data, int size) throws IOException {
        socket.send(data, size);
    }

    public long getChannelId() {
        return channelId;
    }

    @Override
    public void onReceived(byte[] data, int size) {
        if (listener != null) {
            listener.onReceived(this, data, size);
        }
    }

    @Override
    public void onClosed() {
        if (listener != null) {
            listener.onClosed(this);
        }
    }

    @Override
    public void trace(String message) {
        listener.trace("[" + toString() + "]: " + message);
    }

    @Override
    public String toString() {
        return "Channel{" +
                "channelId=" + channelId +
                '}';
    }
}
