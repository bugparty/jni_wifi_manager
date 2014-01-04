package com.ifancc.wifimgr.Bean;

/**
 * @author bowman
 * Created by bowman on 14-1-2.
 */
public class Wifi {
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public WifiType getType() {
        return type;
    }

    public void setType(WifiType type) {
        this.type = type;
    }

    public static enum WifiType {NONE, PSK, WEP}

    ;
    private String name;
    private WifiType type;

    public native Wifi[] getWifiNames();

    public Wifi(String name, WifiType type) {
        this.name = name;
        this.type = type;
    }
}
