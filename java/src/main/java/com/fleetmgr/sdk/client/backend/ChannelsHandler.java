package com.fleetmgr.sdk.client.backend;

import com.fleetmgr.interfaces.ChannelIndicationList;
import com.fleetmgr.interfaces.ChannelResponse;
import com.fleetmgr.sdk.client.Client;
import com.fleetmgr.sdk.client.traffic.Channel;
import com.fleetmgr.sdk.client.traffic.ChannelImpl;
import com.fleetmgr.sdk.client.traffic.socket.Socket;
import com.fleetmgr.sdk.client.traffic.socket.UdpSocket;

import java.io.IOException;
import java.util.*;
import java.util.concurrent.ExecutorService;

/**
 * Created by: Bartosz Nawrot
 * Date: 16.12.2018
 * Description:
 */
public class ChannelsHandler {

    private Client client;

    private ExecutorService executor;

    private HashMap<Long, ChannelImpl> channels;

    ChannelsHandler(Client client, ExecutorService executor) {
        this.client = client;
        this.executor = executor;

        this.channels = new HashMap<>();
    }

    public Collection<Channel> getChannels() {
        return new LinkedList<>(channels.values());
    }

    public List<Channel> getChannels(List<Long> channels) {
        LinkedList<Channel> result = new LinkedList<>();
        for (Long id : channels) {
            result.add(this.channels.get(id));
        }
        return result;
    }

    public Map<Long, Channel> validateChannels(Collection<ChannelResponse> toValidate) {
        Map<Long, Channel> opened = new HashMap<>();
        for (ChannelResponse c : toValidate) {
            try {
                trace("Opening channelImpl, id: " + c.getId());

                Socket socket = new UdpSocket(executor);
                ChannelImpl channel = new ChannelImpl(c.getId(), socket);
                channel.open(c.getHost(), c.getPort(), c.getKey());

                channels.put(c.getId(), channel);
                opened.put(c.getId(), channel);

                trace("ChannelImpl id: " + c.getId() + " validated");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return opened;
    }

    public void closeChannels(Collection<Long> channels) {
        for (Long c : channels) {
            trace("Closing channel, id: " + c);
            ChannelImpl s = this.channels.remove(c);
            if (s != null) {
                s.close();
            } else {
                trace("Warning, trying to close not existing channel, id: " + c);
            }
        }
    }

    public void closeAllChannels() {
        System.out.println(channels);
        for (ChannelImpl c : channels.values()) {
            trace("Closing channel id: " + c.getId());
            c.close();
        }
        System.out.println("asdasdasd");
        channels.clear();
    }

    public void trace(String message) {
        client.trace(message);
    }
}
