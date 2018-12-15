package com.fleetmgr.sdk.client.state.pilot.connected;

import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.FacadeEvent;
import com.fleetmgr.sdk.client.event.output.facade.HandoverAccepted;
import com.fleetmgr.sdk.client.event.output.facade.HandoverRejected;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class RequestingControl extends BaseState {

    RequestingControl(BaseState state) {
        super(state);
    }

    @Override
    public void start() {
        send(ClientMessage.newBuilder()
                .setCommand(Command.REQUEST_CONTROL)
                .build());
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        switch (event.getType()) {
            case CONTROL_READY:
                send(ClientMessage.newBuilder()
                        .setCommand(Command.CONTROL_READY)
                        .build());
                return Optional.empty();

            default:
                return defaultConnectionEventHandler(event.toString());
        }
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
            case REQUEST_CONTROL:
                if (message.getResponse() == Response.ACCEPTED) {
                    listener.onEvent(new HandoverAccepted(
                            message.getHandoverData().getHandoverData().getBytes()));
                    return Optional.empty();

                } else {
                    listener.onEvent(new HandoverRejected(message.getMessage()));
                    return Optional.of(new Spectating(this));
                }

            case CONTROL_READY:
                if (message.getResponse() == Response.ACCEPTED) {
                    listener.onEvent(new FacadeEvent(FacadeEvent.Type.HANDOVER_DONE));
                    return Optional.of(new Controlling(this));

                } else {
                    return defaultUserEventHandler(message);
                }

            default:
                return defaultUserEventHandler(message);
        }
    }

    @Override
    public String toString() {
        return "RequestingControl";
    }
}
