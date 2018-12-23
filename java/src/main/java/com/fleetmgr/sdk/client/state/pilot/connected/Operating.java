package com.fleetmgr.sdk.client.state.pilot.connected;

import com.fleetmgr.interfaces.facade.control.ControlMessage;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.connection.Received;
import com.fleetmgr.sdk.client.event.input.user.CloseChannels;
import com.fleetmgr.sdk.client.event.input.user.OpenChannels;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.FacadeEvent;
import com.fleetmgr.sdk.client.state.State;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Operating extends State {

    Operating(State state) {
        super(state);
    }

    @Override
    public State start() {
        return null;
    }

    @Override
    public State notifyEvent(UserEvent event) {
        switch (event.getType()) {
            case OPEN_CHANNELS:
                OpenChannels openChannels = (OpenChannels)event;
                return new OpeningChannels(this, openChannels.getChannels());

            case CLOSE_CHANNELS:
                CloseChannels closeChannels = (CloseChannels)event;
                return new ClosingChannels(this, closeChannels.getChannels());

            case RELEASE:
                // release is considered as wildcard for closing all channels
                return new ClosingChannels(this, backend.getChannelsHandler().getChannelsIds());

            case REQUEST_CONTROL:
                return new RequestingControl(this);

            default:
                return defaultEventHandle(event.toString());
        }
    }

    @Override
    public State notifyConnection(ConnectionEvent event) {
        switch (event.getType()) {
            case RECEIVED:
                return handleMessage(((Received) event).getMessage());

            case LOST:
                return new Recovering(this);

            default:
                return defaultEventHandle(event.toString());
        }
    }

    private State handleMessage(ControlMessage message) {
        switch (message.getCommand()) {
            case OPERATION_UPDATED:
                listener.onEvent(new FacadeEvent(FacadeEvent.Type.OPERATION_UPDATED));
                return null;

            case RELEASE_CONTROL:
                return new ReleasingControl(this);

            default:
                return defaultMessageHandle(message);
        }
    }

    @Override
    public String toString() {
        return "Operating";
    }
}
