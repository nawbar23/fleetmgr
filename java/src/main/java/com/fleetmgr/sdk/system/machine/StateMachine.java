package com.fleetmgr.sdk.system.machine;

import com.fleetmgr.sdk.system.capsule.Capsule;

import java.util.concurrent.ExecutorService;

/**
 * Created by: Bartosz Nawrot
 * Date: 21.10.2018
 * Description:
 */
public abstract class StateMachine<Event> extends Capsule {

    private State<Event> state;

    public StateMachine(ExecutorService executor, State<Event> initial) {
        super(executor);
        this.state = initial;
    }

    public void notifyEvent(Event event) {
        execute(() -> {
            trace("Handling: " + event + " @ " + state);
            State<Event> newState = state.handleEvent(event);
            while (newState != null) {
                trace("Transition: " + state + " -> " + newState);
                state = newState;
                newState = state.start();
            }
        });
    }

    protected void setState(State<Event> state) {
        this.state = state;
        this.state.start();
    }

    public String getStateName() {
        return state.toString();
    }

    protected abstract void trace(String message);
}
