package com.fleetmgr.sdk.client.event.output.facade;

/**
 * Created by: Bartosz Nawrot
 * Date: 26.09.2018
 * Description:
 */
public class HandoverRejected extends FacadeEvent {

    private String message;

    public HandoverRejected(String message) {
        super(FacadeEvent.Type.HANDOVER_REJECTED);
        this.message = message;
    }

    public String getMessage() {
        return message;
    }

    @Override
    public String toString() {
        return "HandoverRejected{" +
                "message='" + message + '\'' +
                '}';
    }
}
