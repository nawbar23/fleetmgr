package com.fleetmgr.sdk.client.core.https;

import com.fleetmgr.sdk.client.backend.ClientBackend;
import com.google.api.HttpRule;

import javax.net.ssl.HttpsURLConnection;
import javax.net.ssl.SSLContext;
import javax.net.ssl.TrustManager;
import javax.net.ssl.X509TrustManager;
import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;
import java.security.KeyManagementException;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.cert.X509Certificate;
import java.util.logging.Logger;

import static com.google.api.HttpRule.PatternCase.GET;

/**
 * Created by: Bartosz Nawrot
 * Date: 07.11.2018
 * Description:
 */
public class HttpsClient {

    private static final Logger logger = Logger.getLogger(HttpsClient.class.getName());

    static {
        // TODO verify if it is really needed
        logger.warning("Trusting self signed SSL certificates is enabled");
        disableSslVerification();
    }

    private final String address;
    private final String apiKey;

    public HttpsClient(String address, String apiKey) {
        this.address = address;
        this.apiKey = apiKey;
    }

    private static String readResponse(InputStream is) throws IOException {
        BufferedReader in = new BufferedReader(
                new InputStreamReader(is));
        String inputLine;
        StringBuilder content = new StringBuilder();
        while ((inputLine = in.readLine()) != null) {
            content.append(inputLine);
        }
        in.close();
        return content.toString();
    }

    private static void disableSslVerification() {
        try {
            // Create a trust manager that does not validate certificate chains
            TrustManager[] trustAllCerts = new TrustManager[]{new X509TrustManager() {
                public java.security.cert.X509Certificate[] getAcceptedIssuers() {
                    return null;
                }

                public void checkClientTrusted(X509Certificate[] certs, String authType) {
                }

                public void checkServerTrusted(X509Certificate[] certs, String authType) {
                }
            }
            };

            // Install the all-trusting trust manager
            SSLContext sc = SSLContext.getInstance("SSL");
            sc.init(null, trustAllCerts, new SecureRandom());
            HttpsURLConnection.setDefaultSSLSocketFactory(sc.getSocketFactory());

            // Install the all-trusting host verifier
            HttpsURLConnection.setDefaultHostnameVerifier((hostname, session) -> true);

        } catch (NoSuchAlgorithmException | KeyManagementException e) {
            e.printStackTrace();
        }
    }

    public String execute(String path, HttpRule.PatternCase method) throws IOException {
        return execute(path, method, null);
    }

    public String execute(String path, HttpRule.PatternCase method, String body) throws IOException {
        URL url = new URL(address + path);
        logger.info("Execute " + method.name() + ": " + url.toString() + " body: " + body);
        HttpsURLConnection con = (HttpsURLConnection) url.openConnection();
        con.setDoOutput(true);
        con.setDoInput(true);
        con.setRequestProperty("Content-Type", "application/json");
        con.setRequestProperty("Accept", "application/json");
        con.setRequestProperty("Authorization", apiKey);
        con.setRequestMethod(method.name());

        if (method != GET && body != null) {
            OutputStreamWriter wr = new OutputStreamWriter(con.getOutputStream());
            wr.write(body);
            wr.flush();
            wr.close();
        }

        con.setConnectTimeout(8000);
        con.setReadTimeout(8000);

        int result = con.getResponseCode();
        if (result >= HttpURLConnection.HTTP_OK && result < HttpURLConnection.HTTP_MULT_CHOICE) {
            String response = readResponse(con.getInputStream());
            logger.info("Response " + result + ": " + response);
            return response;

        } else {
            String cause = "Request failed with code: " + result;
            if (result >= HttpURLConnection.HTTP_BAD_REQUEST) {
                cause += " " + readResponse(con.getErrorStream());
            }
            throw new IOException(cause);
        }
    }
}
