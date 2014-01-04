/*
 * This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

package com.ifancc.wifimgr;

import com.ifancc.wifimgr.Bean.WlanInterfaceInfo;
import org.junit.Before;
import org.junit.Test;

/**
 * @author bowman
 *         Created by bowman on 14-1-4.
 */
public class WlanInterfaceInfoTest {
    static {
        System.loadLibrary("Debug/wifimgr");
    }
    public native static WlanInterfaceInfo getWlanInterfaceInfo();
    @Test
    public void testGetWlanInterfaceInfo() throws Exception {
        WlanInterfaceInfo info = WlanInterfaceInfoTest.getWlanInterfaceInfo();

        assert ( info!= null);
        System.out.println(info);

    }

    @Before
    public void setUp() throws Exception {


    }
}
