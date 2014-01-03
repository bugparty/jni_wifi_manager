package com.ifancc.wifimgr.Bean;

/**
 * Created by bowman on 14-1-3.
 */

public class WlanInterfaceInfo {
    public  String GUID;
    public String  InterfaceInfo;
    public WlanInterfaceState state;

    public WlanInterfaceInfo(String GUID, String interfaceInfo, WlanInterfaceState state) {
        this.GUID = GUID;
        InterfaceInfo = interfaceInfo;
        this.state = state;
    }
}
