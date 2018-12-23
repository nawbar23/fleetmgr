package com.fleetmgr.sdk.client.traffic;

import com.fleetmgr.interfaces.Result;
import com.fleetmgr.interfaces.ValidateChannelRequest;
import com.fleetmgr.interfaces.ValidateChannelResponse;
import com.fleetmgr.sdk.client.traffic.socket.Socket;

import java.io.IOException;
import java.nio.ByteBuffer;

public class ChannelImpl implements Channel, Socket.Listener {

    private final long id;
    private final Socket socket;

    private Listener listener;

    private boolean owner;

    public ChannelImpl(long id, Socket socket) {
        this.id = id;
        this.socket = socket;
        this.listener = null;
        this.owner = false;
    }

    @Override
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

    public void setOwner(boolean owner) {
        this.owner = owner;
    }

    @Override
    public void send(byte[] data, int size) throws IOException {
        socket.send(data, size);
    }

    @Override
    public long getId() {
        return id;
    }

    @Override
    public boolean isOwner() {
        return owner;
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
                "id=" + id +
                ", protocol=" + socket.getProtocol() +
                '}';
    }
}
