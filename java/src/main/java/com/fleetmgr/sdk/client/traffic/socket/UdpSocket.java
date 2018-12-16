package com.fleetmgr.sdk.client.traffic.socket;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.concurrent.ExecutorService;

/**
 * Created by: Bartosz Nawrot
 * Date: 26.11.2018
 * Description:
 */
public class UdpSocket extends Socket {

    private ExecutorService executor;

    private DatagramSocket socket;

    private InetAddress dstAddress;
    private int dstPort;

    public UdpSocket(ExecutorService executor) {
        this.executor = executor;
    }

    @Override
    public void connect(String ip, int port) throws IOException {
        dstAddress = InetAddress.getByName(ip);
        dstPort = port;
        socket = new DatagramSocket(0);
    }

    @Override
    public void startReading() {
        startReception();
    }

    @Override
    public byte[] readBlocking() throws IOException {
        byte[] buffer = new byte[256];
        DatagramPacket packet = new DatagramPacket(buffer, 256);

        socket.receive(packet);

        byte[] result = new byte[packet.getLength()];
        System.arraycopy(buffer, 0, result, 0, packet.getLength());

        return result;
    }

    @Override
    public void send(byte[] data, int size) throws IOException {
        socket.send(new DatagramPacket(data, size, dstAddress, dstPort));
    }

    @Override
    public void disconnect() {
        socket.close();
        listener.onClosed();
    }

    private void startReception() {
        executor.execute(() -> {
            byte[] buffer = new byte[1024];
            DatagramPacket datagramPacket = new DatagramPacket(buffer, 1024);
            while (!socket.isClosed()) {
                try {
                    socket.receive(datagramPacket);
                    listener.onReceived(
                            datagramPacket.getData(),
                            datagramPacket.getLength());
                } catch (IOException e) {
                    if (!socket.isClosed()) {
                        e.printStackTrace();
                    }
                    break;
                }
            }
        });
    }
}
