package com.fleetmgr.java.sdk.event.output.facade;

import java.util.Collection;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class OperationEnded extends ChannelsClosed {

    public OperationEnded(Collection<Long> sockets) {
        super(FacadeEvent.Type.OPERATION_ENDED, sockets);
    }

    @Override
    public String toString() {
        return "OperationEnded{" +
                ", sockets=" + getSockets() +
                "}";
    }
}
