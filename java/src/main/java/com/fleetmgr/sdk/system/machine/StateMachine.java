package com.fleetmgr.sdk.system.machine;

import com.fleetmgr.sdk.client.event.input.Event;
import com.fleetmgr.sdk.client.traffic.Channel;
import com.fleetmgr.sdk.system.capsule.Capsule;

import java.util.Optional;
import java.util.concurrent.ExecutorService;
import java.util.logging.Logger;

/**
 * Created by: Bartosz Nawrot
 * Date: 21.10.2018
 * Description:
 */
public abstract class StateMachine<E extends Event> extends Capsule {

    private static final Logger logger = Logger.getLogger(StateMachine.class.getName());

    private BaseState state;

    public StateMachine(ExecutorService executor, BaseState initial) {
        super(executor);
        this.state = initial;
    }

    public void notifyEvent(E event) {
        execute(() -> {
            logger.info("Handling: " + event + " @ " + state);

            Optional<BaseState> newState = state.handleEvent(event);

            while (newState.isPresent()) {
                logger.info("Transition: " + state + " -> " + newState);
                state = newState.get();

                state.start();
                newState = state.getInitialState();
            }
        });
    }

    protected void setState(BaseState state) {
        this.state = state;
        this.state.start();
    }

    public String getStateName() {
        return state.toString();
    }
}
