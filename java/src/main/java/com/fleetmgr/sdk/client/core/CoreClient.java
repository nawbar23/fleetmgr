package com.fleetmgr.sdk.client.core;

import com.fleetmgr.interfaces.AttachResponse;
import com.fleetmgr.interfaces.ListDevicesResponse;
import com.fleetmgr.interfaces.OperateRequest;
import com.fleetmgr.interfaces.OperateResponse;
import com.fleetmgr.sdk.client.core.https.HttpsClient;
import com.google.protobuf.util.JsonFormat;
import org.json.JSONArray;
import org.json.JSONObject;

import java.io.IOException;
import java.sql.Timestamp;
import java.text.SimpleDateFormat;

import static com.google.api.HttpRule.PatternCase.GET;
import static com.google.api.HttpRule.PatternCase.POST;

/**
 * Created by: Bartosz Nawrot
 * Date: 23.09.2018
 * Description:
 */
public class CoreClient {

    private final HttpsClient client;

    public CoreClient(String address, String key) {
        this.client = new HttpsClient(address, key, this::trace);
    }

    public AttachResponse attach() throws IOException {
        String path = "/gateway/devices/attach";
        String response = client.execute(path, POST);
        AttachResponse.Builder builder = AttachResponse.newBuilder();
        JsonFormat.parser().ignoringUnknownFields().merge(response, builder);
        return builder.build();
    }

    public OperateResponse operate(OperateRequest request) throws IOException {
        String path = "/gateway/pilots/operate";
        String body = JsonFormat.printer().print(request);
        String response = client.execute(path, POST, body);
        OperateResponse.Builder builder = OperateResponse.newBuilder();
        JsonFormat.parser().ignoringUnknownFields().merge(response, builder);
        return builder.build();
    }

    public ListDevicesResponse listDevices() throws IOException {
        String path = "/devices/";
        String response = client.execute(path, GET);
        JSONObject responseJson = new JSONObject();
        responseJson.put("devices", new JSONArray(response));
        ListDevicesResponse.Builder builder = ListDevicesResponse.newBuilder();
        JsonFormat.parser().ignoringUnknownFields().merge(responseJson.toString(), builder);
        return builder.build();
    }

    private static final SimpleDateFormat sdf = new SimpleDateFormat("HH.mm.ss.SSS");

    public void trace(String message) {
        System.out.println(sdf.format(new Timestamp(System.currentTimeMillis())) + ": " + message);
    }
}
