package com.ifancc.wifimgr.Bean;

/**
 * @author bowman
 * Created by bowman on 14-1-3.
 */

public class WlanInterfaceInfo {
    public String GUID;
    public String InterfaceInfo;
    public WlanInterfaceState State;

    static {
        System.loadLibrary("Debug/wifimgr");
    }

    public WlanInterfaceInfo(String GUID, String interfaceInfo, WlanInterfaceState state) {
        this.GUID = GUID;
        InterfaceInfo = interfaceInfo;
        this.State = state;
    }

    public native static WlanInterfaceInfo getWlanInterfaceInfo();
}
