package com.fleetmgr.client.sdk.event.output.facade;

/**
 * Created by: Bartosz Nawrot
 * Date: 26.09.2018
 * Description:
 */
public class HandoverRejected extends Message {

    public HandoverRejected(String message) {
        super(Type.HANDOVER_REJECTED, message, MessageType.ERROR);
    }

    @Override
    public String toString() {
        return "HandoverRejected{" +
                "mesage='" + message + '\'' +
                '}';
    }
}
