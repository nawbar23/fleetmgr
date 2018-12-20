package com.fleetmgr.sdk.client.event.output.facade;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class FacadeEvent {

    public enum Type {
        ATTACHED,
        RELEASED,
        ERROR,
        MESSAGE,
        CHANNELS_OPENED,
        OPERATION_STARTED,
        HANDOVER_ACCEPTED,
        REQUEST_CONTROL,
        RELEASE_CONTROL,
        HANDOVER_REJECTED,
        HANDOVER_DONE,
        CONTROL_RELEASED,
        CHANNELS_CLOSING,
        CHANNELS_CLOSED,
        OPERATION_ENDED,
        CONNECTION_LOST,
        CONNECTION_RECOVERED,
        DEVICE_UNREACHABLE,
        LEADER_UNREACHABLE,
        DEVICE_RECOVERED,
    }

    private Type type;

    public FacadeEvent(Type type) {
        this.type = type;
    }

    public Type getType() {
        return type;
    }

    @Override
    public String toString() {
        return "FacadeEvent{" +
                "type=" + type +
                '}';
    }
}
