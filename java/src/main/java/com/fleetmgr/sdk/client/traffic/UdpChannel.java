package com.fleetmgr.sdk.client.traffic;

import com.fleetmgr.interfaces.Result;
import com.fleetmgr.interfaces.ValidateChannelRequest;
import com.fleetmgr.interfaces.ValidateChannelResponse;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.concurrent.ExecutorService;

public class UdpChannel extends Channel {

    private ExecutorService executor;

    private DatagramSocket socket;

    private InetAddress dstAddress;
    private int dstPort;

    public UdpChannel(ExecutorService executor, String ip, int port,
                      long channelId, Listener listener) throws IOException {
        super(channelId, listener);

        this.executor = executor;

        this.dstAddress = InetAddress.getByName(ip);
        this.dstPort = port;
    }

    public void initialize(String key) throws IOException {
        socket = new DatagramSocket(0);

        ValidateChannelRequest validateChannelRequest = ValidateChannelRequest.newBuilder()
                .setKey(key)
                .build();

        send(validateChannelRequest.toByteArray(), validateChannelRequest.getSerializedSize());

        waitForValidationResponse();

        startReception();
    }

    @Override
    public void send(byte[] data, int size) throws IOException {
        socket.send(new DatagramPacket(data, size, dstAddress, dstPort));
    }

    @Override
    public void close() {
        listener.onClosed(this);
        socket.close();
    }

    private void waitForValidationResponse() throws IOException {
        byte[] buffer = new byte[256];
        DatagramPacket packet = new DatagramPacket(buffer, 256);

        trace("Waiting for router response");
        socket.receive(packet);

        byte[] test = new byte[packet.getLength()];
        System.arraycopy(buffer, 0, test, 0, packet.getLength());

        ValidateChannelResponse response = ValidateChannelResponse.parseFrom(test);
        if (response.getResult() != Result.VALIDATION_ACCEPTED) {
            throw new IOException("Channel validation rejected");
        }
    }

    private void startReception() {
        executor.execute(() -> {
            byte[] buffer = new byte[1024];
            DatagramPacket datagramPacket = new DatagramPacket(buffer, 1024);
            while (!socket.isClosed()) {
                try {
                    socket.receive(datagramPacket);
                    listener.onReceived(this,
                            datagramPacket.getData(),
                            datagramPacket.getLength());
                } catch (IOException e) {
                    if (!socket.isClosed()) {
                        e.printStackTrace();
                    }
                    break;
                }
            }
            trace("Reception thread ended");
        });
    }

    @Override
    public String toString() {
        return "UDP{" +
                "channelId=" + channelId +
                '}';
    }
}
