package com.fleetmgr.sdk.system;

import java.util.Objects;

/**
 * Created by: Bartosz Nawrot
 * Date: 12.12.2018
 * Description:
 */
public class Pair<A, B> {
    private A key;
    private B value;

    public Pair(A key, B value) {
        this.key = key;
        this.value = value;
    }

    public A getKey() {
        return key;
    }

    public void setKey(A first) {
        this.key = first;
    }

    public B getValue() {
        return value;
    }

    public void setValue(B second) {
        this.value = second;
    }

    @Override
    public String toString() {
        return "Pair{" +
                "key=" + key +
                ", value=" + value +
                '}';
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) return true;
        if (other == null || getClass() != other.getClass()) return false;
        Pair<?, ?> pair = (Pair<?, ?>) other;
        return Objects.equals(key, pair.key) &&
                Objects.equals(value, pair.value);
    }

    @Override
    public int hashCode() {
        return Objects.hash(key, value);
    }
}
