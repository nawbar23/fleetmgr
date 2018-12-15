package com.fleetmgr.sdk.system;

import java.util.Random;

public enum RandomString {

    ;

    private static final char[] SYMBOLS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz01234567890".toCharArray();

    private static final Random random;

    static {
        random = new Random();
    }

    public static String nextString(int size) {
        StringBuilder sb = new StringBuilder(size);
        for (int i = 0; i < size; i++) {
            sb.append(SYMBOLS[random.nextInt(SYMBOLS.length)]);
        }

        return sb.toString();
    }
}
