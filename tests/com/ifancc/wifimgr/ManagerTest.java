package com.ifancc.wifimgr;

import com.ifancc.wifimgr.Bean.Wifi;
import com.ifancc.wifimgr.Bean.WlanInterfaceState;
import junit.framework.TestCase;
import org.junit.Before;
import org.junit.Test;

import java.lang.reflect.Method;

/**
 *@author bowman
 * Created by bowman on 14-1-2.
 */
public class ManagerTest extends TestCase {
    private Manager mgr;

    @Override
    protected  void setUp() throws Exception{
        mgr = new Manager();

    }



    public void testGetWifiList() throws Exception {

        Wifi[] list = mgr.getWifiList();
        assertNotNull(list);
        for(Wifi w:list){
            System.out.println(w.getName()+":"+w.getType());
        }
    }


}
