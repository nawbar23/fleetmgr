package com.fleetmgr.sdk.client.traffic.socket;

import java.io.IOException;

/**
 * Created by: Bartosz Nawrot
 * Date: 26.11.2018
 * Description:
 */
public class TcpSocket extends Socket {

    @Override
    public void connect(String ip, int port) throws IOException {

    }

    @Override
    public void startReading() {

    }

    @Override
    public byte[] readBlocking() throws IOException {
        return new byte[0];
    }

    @Override
    public void send(byte[] data, int size) throws IOException {

    }

    @Override
    public void disconnect() {

    }
}
