package com.fleetmgr.sdk.client.event.output.facade;

/**
 * Created by: Bartosz Nawrot
 * Date: 26.09.2018
 * Description:
 */
public class Error extends Message {

    public Error(String message) {
        super(message, MessageType.ERROR, Type.ERROR);
    }

    @Override
    public String toString() {
        return "Error{" +
                "message='" + message + '\'' +
                '}';
    }
}
