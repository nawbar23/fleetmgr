package com.fleetmgr.sdk.client.traffic.socket;

import com.fleetmgr.interfaces.Protocol;

import java.io.IOException;

/**
 * Created by: Bartosz Nawrot
 * Date: 26.11.2018
 * Description:
 */
public abstract class Socket {

    public interface Listener {
        void onReceived(byte[] data, int size);
        void onClosed();
        void trace(String message);
    }

    protected Listener listener;

    public void setListener(Listener listener)
    {
        this.listener = listener;
    }

    public abstract void connect(String ip, int port) throws IOException;

    public abstract void startReading();

    public abstract int readBlocking(byte[] data) throws IOException;

    public abstract void send(byte[] data, int size) throws IOException;

    public abstract void disconnect();

    public abstract Protocol getProtocol();
}
