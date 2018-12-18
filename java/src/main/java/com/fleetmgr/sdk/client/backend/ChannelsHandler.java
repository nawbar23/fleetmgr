package com.fleetmgr.sdk.client.backend;

import com.fleetmgr.sdk.client.Client;
import com.fleetmgr.sdk.client.traffic.Channel;
import com.fleetmgr.sdk.client.traffic.socket.Socket;
import com.fleetmgr.sdk.client.traffic.socket.UdpSocket;

import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ExecutorService;

/**
 * Created by: Bartosz Nawrot
 * Date: 16.12.2018
 * Description:
 */
public class ChannelsHandler {

    private Client client;

    private ExecutorService executor;

    private HashMap<Long, Channel> channels;

    ChannelsHandler(Client client, ExecutorService executor) {
        this.client = client;
        this.executor = executor;

        this.channels = new HashMap<>();
    }

    public Collection<Long> getChannelIds() {
        return channels.keySet();
    }

    public Map<Long, Channel> validateChannels(Collection<com.fleetmgr.interfaces.Channel> toValidate) {
        Map<Long, Channel> opened = new HashMap<>();
        for (com.fleetmgr.interfaces.Channel c : toValidate) {
            try {
                trace("Opening channel, id: " + c.getId());

                Socket socket = new UdpSocket(executor);
                Channel channel = new Channel(c.getId(), socket);
                channel.open(c.getIp(), c.getPort(), c.getRouteKey());

                channels.put(c.getId(), channel);
                opened.put(c.getId(), channel);

                trace("Channel id: " + c.getId() + " validated");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return opened;
    }

    public void closeChannels(Collection<Long> channels) {
        for (Long c : channels) {
            trace("Closing channel, id: " + c);
            Channel s = this.channels.remove(c);
            if (s != null) {
                s.close();
            } else {
                trace("Warning, trying to close not existing channel, id: " + c);
            }
        }
    }

    public void closeAllChannels() {
        for (Channel c : channels.values()) {
            trace("Closing channel id: " + c.getChannelId());
            c.close();
        }
        channels.clear();
    }

    public void trace(String message) {
        client.trace(message);
    }
}
