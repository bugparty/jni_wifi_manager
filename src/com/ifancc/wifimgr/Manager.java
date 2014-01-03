package com.ifancc.wifimgr;

import com.ifancc.wifimgr.Bean.Wifi;
import com.ifancc.wifimgr.Bean.WlanInterfaceInfo;

/**
 * Created by bowman on 14-1-2.
 */
public class Manager {
    static {
        System.loadLibrary("Debug/wifimgr");
    }
    public native Wifi[] getWifiList();
    public native WlanInterfaceInfo[] getWlanInterface();
}
