package com.fleetmgr.sdk.client.backend;

import com.fleetmgr.sdk.client.Client;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.interfaces.facade.control.*;
import com.fleetmgr.sdk.system.capsule.Timer;

import java.util.concurrent.atomic.AtomicLong;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.11.2018
 * Description:
 */
public class HeartbeatHandler {

    private static final int VERIFICATION_INTERVAL = 5; // [s]
    private static final int MAX_SILENT_INTERVAL = 15; // [s]

    private Client client;
    private ClientBackend backend;

    private Timer timer;

    private AtomicLong lastReception;

    HeartbeatHandler(Client client, ClientBackend backend) {
        this.client = client;
        this.backend = backend;

        this.lastReception = new AtomicLong(0);
    }

    public void start() {
        client.trace("Starting heartbeat verification task");

        lastReception.set(System.currentTimeMillis());

        timer = client.executeEvery(this::onTimeout,
                VERIFICATION_INTERVAL * 1000,
                VERIFICATION_INTERVAL * 1000);
    }

    public void end() {
        client.trace("Ending heartbeat verification task");
        if (timer != null) {
            timer.cancel();
            timer = null;
        }
    }

    public void handleHeartbeat(ControlMessage message) {
        lastReception.set(System.currentTimeMillis());
        backend.send(ClientMessage.newBuilder()
                .setCommand(Command.HEARTBEAT)
                .setResponse(Response.ACCEPTED)
                .setHeartbeat(HeartbeatResponse.newBuilder()
                        .setKey(message.getHeartbeat().getKey())
                        .setLocation(backend.getLocation())
                        .build())
                .build());
    }

    private void onTimeout() {
        long silentTime = System.currentTimeMillis() - lastReception.get();
        if (silentTime > MAX_SILENT_INTERVAL * 1000) {
            client.notifyEvent(new ConnectionEvent(ConnectionEvent.Type.LOST));
        }
    }
}