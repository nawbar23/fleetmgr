package com.fleetmgr.client.sdk.state.pilot.connected;

import com.fleetmgr.client.sdk.event.input.connection.ConnectionEvent;
import com.fleetmgr.client.sdk.event.input.connection.Received;
import com.fleetmgr.client.sdk.event.input.user.UserEvent;
import com.fleetmgr.client.sdk.event.output.facade.HandoverRejected;
import com.fleetmgr.client.sdk.event.output.facade.FacadeEvent;
import com.fleetmgr.client.sdk.event.output.facade.HandoverAccepted;
import com.fleetmgr.client.sdk.state.State;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class RequestingControl extends State {

    RequestingControl(State state) {
        super(state);
    }

    @Override
    public State start() {
        send(ClientMessage.newBuilder()
                .setCommand(Command.REQUEST_CONTROL)
                .build());
        return null;
    }

    @Override
    public State notifyConnection(ConnectionEvent event) {
        switch (event.getType()) {
            case RECEIVED:
                return handleMessage(((Received)event).getMessage());

            default:
                return defaultEventHandle(event.toString());
        }
    }

    @Override
    public State notifyEvent(UserEvent event) {
        switch (event.getType()) {
            case CONTROL_READY:
                send(ClientMessage.newBuilder()
                        .setCommand(Command.CONTROL_READY)
                        .build());
                return null;

            default:
                return defaultEventHandle(event.toString());
        }
    }

    private State handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            case REQUEST_CONTROL:
                if (message.getResponse() == Response.ACCEPTED) {
                    listener.onEvent(new HandoverAccepted(
                            message.getHandoverData().getHandoverData().getBytes()));
                    return null;

                } else {
                    listener.onEvent(new HandoverRejected(message.getMessage()));
                    return new Spectating(this);
                }

            case CONTROL_READY:
                if (message.getResponse() == Response.ACCEPTED) {
                    listener.onEvent(new FacadeEvent(FacadeEvent.Type.HANDOVER_DONE));
                    return new Controlling(this);

                } else {
                    return defaultMessageHandle(message);
                }

            default:
                return defaultMessageHandle(message);
        }
    }

    @Override
    public String toString() {
        return "RequestingControl";
    }
}
