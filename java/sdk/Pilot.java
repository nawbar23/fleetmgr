package com.fleetmgr.java.sdk;

import com.fleetmgr.java.sdk.state.pilot.Disconnected;
import com.fleetmgr.interfaces.ConnectionState;
import com.fleetmgr.interfaces.Device;
import com.fleetmgr.interfaces.ListDevicesResponse;

import java.io.IOException;
import java.util.concurrent.ExecutorService;

/**
 * Created by: Bartosz Nawrot
 * Date: 04.09.2018
 * Description:
 */
public class Pilot extends Client {

    public Pilot(String coreAddress, String key, Listener listener,
                 ExecutorService executor) {
        super(coreAddress, key, listener, executor);
        setState(new Disconnected(key, this, coreClient, listener, executor));
    }

    public ListDevicesResponse listDevices() throws IOException {
        return coreClient.listDevices();
    }

    public ListDevicesResponse listConnectedDevices() throws IOException {
        ListDevicesResponse.Builder builder = ListDevicesResponse.newBuilder();
        ListDevicesResponse response = listDevices();
        for (Device d : response.getDevicesList()) {
            if (d.getConnectionState() == ConnectionState.CONNECTED) {
                builder.addDevices(d);
            }
        }
        return builder.build();
    }
}
