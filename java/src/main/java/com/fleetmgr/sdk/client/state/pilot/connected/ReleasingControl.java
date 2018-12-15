package com.fleetmgr.sdk.client.state.pilot.connected;

import com.fleetmgr.interfaces.HandoverData;
import com.fleetmgr.interfaces.facade.control.ClientMessage;
import com.fleetmgr.interfaces.facade.control.Command;
import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.interfaces.facade.control.Response;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.ReleaseAccepted;
import com.fleetmgr.sdk.client.event.input.user.ReleaseRejected;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.FacadeEvent;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Optional;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class ReleasingControl extends BaseState {

    ReleasingControl(BaseState state) {
        super(state);
    }

    @Override
    public void start() {
        listener.onEvent(new FacadeEvent(FacadeEvent.Type.RELEASE_CONTROL));
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        switch (event.getType()) {
            case RELEASE_ACCEPTED:
                ReleaseAccepted releaseAccepted = (ReleaseAccepted) event;
                send(ClientMessage.newBuilder()
                        .setCommand(Command.RELEASE_CONTROL)
                        .setResponse(Response.ACCEPTED)
                        .setHandoverData(HandoverData.newBuilder()
                                .setHandoverData(new String(releaseAccepted.getData()))
                                .build())
                        .build());
                return Optional.empty();

            case RELEASE_REJECTED:
                ReleaseRejected releaseRejected = (ReleaseRejected) event;
                send(ClientMessage.newBuilder()
                        .setCommand(Command.RELEASE_CONTROL)
                        .setResponse(Response.REJECTED)
                        .setMessage(releaseRejected.getMessage())
                        .build());
                return Optional.of(new Controlling(this));

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
            case CONTROL_RELEASED:
                listener.onEvent(new FacadeEvent(FacadeEvent.Type.CONTROL_RELEASED));
                send(ClientMessage.newBuilder()
                        .setCommand(Command.CONTROL_RELEASED)
                        .setResponse(Response.ACCEPTED)
                        .build());
                return Optional.of(new Spectating(this));

            default:
                return defaultUserEventHandler(message);
        }
    }

    @Override
    public String toString() {
        return "ReleasingControl";
    }
}
