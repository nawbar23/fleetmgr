package com.fleetmgr.client.sdk.state.pilot.connected;

import com.fleetmgr.client.sdk.event.input.connection.ConnectionEvent;
import com.fleetmgr.client.sdk.event.input.connection.Received;
import com.fleetmgr.client.sdk.event.input.user.ReleaseAccepted;
import com.fleetmgr.client.sdk.event.input.user.ReleaseRejected;
import com.fleetmgr.client.sdk.event.input.user.UserEvent;
import com.fleetmgr.client.sdk.event.output.facade.FacadeEvent;
import com.fleetmgr.client.sdk.state.State;
import com.fleetmgr.interfaces.HandoverData;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class ReleasingControl extends State {

    ReleasingControl(State state) {
        super(state);
    }

    @Override
    public State start() {
        listener.onEvent(new FacadeEvent(FacadeEvent.Type.RELEASE_CONTROL));
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
            case RELEASE_ACCEPTED:
                ReleaseAccepted releaseAccepted = (ReleaseAccepted)event;
                send(ClientMessage.newBuilder()
                        .setCommand(Command.RELEASE_CONTROL)
                        .setResponse(Response.ACCEPTED)
                        .setHandoverData(HandoverData.newBuilder()
                                .setHandoverData(new String(releaseAccepted.getData()))
                                .build())
                        .build());
                return null;

            case REJECT_HANDOVER:
                ReleaseRejected releaseRejected = (ReleaseRejected)event;
                send(ClientMessage.newBuilder()
                        .setCommand(Command.RELEASE_CONTROL)
                        .setResponse(Response.REJECTED)
                        .setMessage(releaseRejected.getMessage())
                        .build());
                return new Controlling(this);

            default:
                return defaultEventHandle(event.toString());
        }
    }

    private State handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            case CONTROL_RELEASED:
                listener.onEvent(new FacadeEvent(FacadeEvent.Type.CONTROL_RELEASED));
                send(ClientMessage.newBuilder()
                        .setCommand(Command.CONTROL_RELEASED)
                        .setResponse(Response.ACCEPTED)
                        .build());
                return new Spectating(this);

            default:
                return defaultMessageHandle(message);
        }
    }

    @Override
    public String toString() {
        return "ReleasingControl";
    }
}
