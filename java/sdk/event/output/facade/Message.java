package com.fleetmgr.java.sdk.event.output.facade;

/**
 * Created by: Bartosz Nawrot
 * Date: 26.09.2018
 * Description:
 */
public class Message extends FacadeEvent {

    public enum MessageType {
        INFORMATION,
        WARNING,
        ERROR,
    }

    private MessageType messageType;
    protected String message;

    Message(Type type, String message, MessageType messageType) {
        super(type);
        this.messageType = messageType;
        this.message = message;
    }

    public Message(String message, MessageType messageType) {
        super(Type.MESSAGE);
        this.messageType = messageType;
        this.message = message;
    }

    public MessageType getMessageType() {
        return messageType;
    }

    public String getMessage() {
        return message;
    }

    @Override
    public String toString() {
        return "Message{" +
                "message='" + message + '\'' +
                '}';
    }
}
