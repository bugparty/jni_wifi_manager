package com.ifancc.wifimgr.Bean;

/**
 * @author bowman
 * Created by bowman on 14-1-3.
 */

public class WlanInterfaceInfo {
    public String GUID;
    public String InterfaceInfo;
    public WlanInterfaceState State;



    public WlanInterfaceInfo(String GUID, String interfaceInfo, WlanInterfaceState state) {
        this.GUID = GUID;
        InterfaceInfo = interfaceInfo;
        this.State = state;
    }


    @Override
    public String toString() {
        return "WlanInterfaceInfo{" +
                "GUID='" + GUID + '\'' +
                ", InterfaceInfo='" + InterfaceInfo + '\'' +
                ", State=" + State +
                '}';
    }
}
