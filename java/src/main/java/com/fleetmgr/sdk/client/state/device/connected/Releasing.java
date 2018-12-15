package com.fleetmgr.sdk.client.state.device.connected;

import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.traffic.Channel;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Optional;
import java.util.logging.Logger;

/**
 * Created by: Bartosz Nawrot
 * Date: 24.09.2018
 * Description:
 */
public class Releasing extends BaseState {

    private static final Logger logger = Logger.getLogger(Releasing.class.getName());

    Releasing(BaseState state) {
        super(state);
    }

    @Override
    public void start() {
        backend.closeAllChannels();
        send(ClientMessage.newBuilder()
                .setCommand(Command.RELEASE)
                .build());
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        return defaultConnectionEventHandler(event.toString());
    }

    @Override
    public Optional<BaseState> onConnectionEvent(ConnectionEvent event) {
        switch (event.getType()) {
            case RECEIVED:
                return handleMessage(((Received) event).getMessage());

            default:
                return defaultConnectionEventHandler(event.toString());
        }
    }

    private Optional<BaseState> handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            case RELEASE:
                if (message.getResponse() == Response.ACCEPTED) {
                    return Optional.of(new Released(this));

                } else {
                    return defaultUserEventHandler(message);
                }

            case HEARTBEAT:
                logger.warning("Heartbeat ignored during release procedure");
                return Optional.empty();

            default:
                return defaultUserEventHandler(message);
        }
    }

    @Override
    public String toString() {
        return "Releasing";
    }
}
