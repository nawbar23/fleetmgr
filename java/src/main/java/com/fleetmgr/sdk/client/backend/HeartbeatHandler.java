package com.fleetmgr.sdk.client.backend;

import com.fleetmgr.interfaces.facade.control.*;
import com.fleetmgr.sdk.client.Client;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.system.capsule.Timer;

import java.util.concurrent.atomic.AtomicLong;
import java.util.logging.Logger;

import static com.fleetmgr.sdk.client.Constants.MAX_SILENT_INTERVAL_SEC;
import static com.fleetmgr.sdk.client.Constants.VERIFICATION_INTERVAL_SEC;
import static java.util.concurrent.TimeUnit.SECONDS;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.11.2018
 * Description:
 */
public class HeartbeatHandler {

    private static final Logger logger = Logger.getLogger(HeartbeatHandler.class.getName());

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
        logger.info("Start heartbeat verification task");
        lastReception.set(System.nanoTime());

        long interval = SECONDS.toMillis(VERIFICATION_INTERVAL_SEC);
        timer = client.executeEvery(this::onTimeout, interval, interval);
    }

    public void end() {
        logger.info("End heartbeat verification task");
        if (timer != null) {
            timer.cancel();
        }
    }

    public void handleHeartbeat(ControlMessage message) {
        lastReception.set(System.nanoTime());

        HeartbeatResponse heartbeatResponse = HeartbeatResponse.newBuilder()
                .setKey(message.getHeartbeat().getKey())
                .setLocation(backend.getLocation())
                .build();

        backend.send(ClientMessage.newBuilder()
                .setCommand(Command.HEARTBEAT)
                .setResponse(Response.ACCEPTED)
                .setHeartbeat(heartbeatResponse)
                .build());
    }

    private void onTimeout() {
        long silentTime = System.nanoTime() - lastReception.get();

        if (silentTime > SECONDS.toNanos(MAX_SILENT_INTERVAL_SEC)) {
            client.notifyEvent(new ConnectionEvent(ConnectionEvent.Type.LOST));
        }
    }
}
