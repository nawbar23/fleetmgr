package com.fleetmgr.client.sdk;

import com.fleetmgr.client.sdk.state.device.Disconnected;

import java.util.concurrent.ExecutorService;

/**
 * Created by: Bartosz Nawrot
 * Date: 04.09.2018
 * Description:
 */
public class Device extends Client {

    public Device(String coreAddress, String key,
                  Listener listener, ExecutorService executor) {
        super(coreAddress, key, listener, executor);
        setState(new Disconnected(key,this, coreClient, listener, executor));
    }
}
