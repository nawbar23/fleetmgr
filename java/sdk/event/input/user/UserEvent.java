package com.fleetmgr.client.sdk.event.input.user;

import com.fleetmgr.client.sdk.event.input.Event;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class UserEvent implements Event {

    public enum Type {
        ATTACH,
        RELEASE,
        OPERATE,
        REQUEST_CONTROL,
        RELEASE_ACCEPTED,
        REJECT_HANDOVER,
        CONTROL_READY,
        OPEN_CHANNELS,
        CLOSE_CHANNELS,
    }

    private Type type;

    public UserEvent(Type type) {
        this.type = type;
    }

    public Type getType() {
        return type;
    }

    @Override
    public String toString() {
        return "UserEvent{" +
                "type=" + type +
                '}';
    }
}
