package com.fleetmgr.sdk.client.state.device;

import com.fleetmgr.sdk.client.event.input.Event;
import com.fleetmgr.sdk.client.event.input.connection.ConnectionEvent;
import com.fleetmgr.sdk.client.event.input.user.UserEvent;
import com.fleetmgr.sdk.client.event.output.facade.FacadeEvent;
import com.fleetmgr.sdk.client.state.device.connected.Ready;
import com.fleetmgr.sdk.client.state.device.connected.Recovering;
import com.fleetmgr.sdk.client.state.device.connected.Released;
import com.fleetmgr.sdk.client.traffic.Channel;
import com.fleetmgr.sdk.system.machine.BaseState;

import java.util.Optional;
import java.util.logging.Logger;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class Connected extends BaseState {

    private static final Logger logger = Logger.getLogger(Connected.class.getName());


    private BaseState internalState;

    Connected(BaseState state) {
        super(state);
        this.internalState = new Ready(this);
    }

    @Override
    public void start() {
        internalState.start();
        backend.getHeartbeatHandler().start();
        listener.onEvent(new FacadeEvent(FacadeEvent.Type.ATTACHED));
    }

    @Override
    public Optional<BaseState> onUserEvent(UserEvent event) {
        return handle(event);
    }

    @Override
    public Optional<BaseState> onConnectionEvent(ConnectionEvent event) {
        return handle(event);
    }

    private Optional<BaseState> handle(Event event) {
        Optional<BaseState> newState = internalState.handleEvent(event);
        boolean wasRecovering = internalState instanceof Recovering;

        while (newState.isPresent()) {
            logger.info("Connected transition: " + toString() + " -> Connected." + newState.toString());
            internalState = newState.get();

            internalState.start();
            newState = internalState.getInitialState();
        }

        if (internalState instanceof Released) {
            return Optional.of(new Disconnecting(this, wasRecovering));
        }

        return Optional.empty();
    }

    @Override
    public String toString() {
        return "Connected." + internalState;
    }
}
