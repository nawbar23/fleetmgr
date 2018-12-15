package com.fleetmgr.sdk.client.event.output.facade;

/**
 * Created by: Bartosz Nawrot
 * Date: 26.09.2018
 * Description:
 */
public class HandoverRejected extends Message {

    public HandoverRejected(String message) {
        super(message, MessageType.ERROR, Type.HANDOVER_REJECTED);
    }

    @Override
    public String toString() {
        return "HandoverRejected{" +
                "mesage='" + message + '\'' +
                '}';
    }
}
