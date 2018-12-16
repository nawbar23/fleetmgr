package com.fleetmgr.sdk.client.event.output.facade;

import java.util.Collection;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class OperationEnded extends FacadeEvent {

    private Collection<Long> channels;

    public OperationEnded(Collection<Long> channels) {
        super(FacadeEvent.Type.OPERATION_ENDED);
        this.channels = channels;
    }

    @Override
    public String toString() {
        return "OperationEnded{" +
                ", sockets=" + channels +
                "}";
    }
}
