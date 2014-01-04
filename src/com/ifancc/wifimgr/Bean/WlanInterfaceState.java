package com.ifancc.wifimgr.Bean;

/**
 * @author bowman
 *         Created by bowman on 14-1-3.
 */
public enum WlanInterfaceState {
    not_ready(0),
    connected(1),
    ad_hoc_network_formed(2),
    disconnecting(3),
    disconnected(4),
    associating(5),
    discovering(6),
    authenticating(7);

    static {
        System.loadLibrary("Debug/wifimgr");
    }

    private int value;

    private WlanInterfaceState(int value) {
        this.value = value;
    }

    public static void main(String[] args) {
        System.out.println(not_ready.toString());
    }

    public static native WlanInterfaceState getWlanInterfaceState(int num);

    @Override
    public String toString() {
        return "WlanInterfaceState:" + super.toString() + "{" +
                "value=" + value +
                '}';
    }
}
