package com.fleetmgr.client.sdk.event.output.facade;

import com.fleetmgr.interfaces.Role;

/**
 * Created by: Bartosz Nawrot
 * Date: 18.09.2018
 * Description:
 */
public class OperationStarted extends FacadeEvent {

    private Role role;

    public OperationStarted(Role role) {
        super(Type.OPERATION_STARTED);
        this.role = role;
    }

    public Role getRole() {
        return role;
    }

    @Override
    public String toString() {
        return "OperationStarted{" +
                "role=" + role +
                '}';
    }
}
