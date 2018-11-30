package com.fleetmgr.client.sdk.event.input.user;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class ReleaseRejected extends UserEvent {

    private String message;

    public ReleaseRejected(String message) {
        super(Type.REJECT_HANDOVER);
        this.message = message;
    }

    public String getMessage() {
        return message;
    }

    @Override
    public String toString() {
        return "ReleaseRejected{" +
                "message='" + message + '\'' +
                '}';
    }
}
