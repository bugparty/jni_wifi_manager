package com.ifancc.wifimgr.Bean;

import java.util.Arrays;

/**
 * @author bowman
 *         Created by bowman on 14-1-3.
 */
public class WlanInterfaceInfoList {
    private int size;
    private int index;
    private WlanInterfaceInfo[] interfaces;

    public WlanInterfaceInfoList() {
    }

    public WlanInterfaceInfoList(int size, int index, WlanInterfaceInfo[] interfaces) {
        this.size = size;
        this.index = index;
        this.interfaces = interfaces;
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public WlanInterfaceInfo[] getInterfaces() {
        return interfaces;
    }

    public void setInterfaces(WlanInterfaceInfo[] interfaces) {
        this.interfaces = interfaces;
    }

    public int getSize() {
        return size;
    }

    @Override
    public String toString() {
        return "WlanInterfaceInfoList{" +
                "size=" + size +
                ", index=" + index +
                ", interfaces=" + Arrays.toString(interfaces) +
                '}';
    }
}
