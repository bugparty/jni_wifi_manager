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

import com.ifancc.wifimgr.Bean.WlanInterfaceInfoList;
import org.junit.Before;
import org.junit.Test;

/**
 * Created by bowman on 14-1-5.
 */
public class ManagerTest {
    private Manager mgr;
    @Test
    public void testWlanEnumInterfaces() throws Exception {
       WlanInterfaceInfoList list =  mgr.WlanEnumInterfaces();
       assert(list != null);
       System.out.println(list);
    }

    @Before
    public void setUp() throws Exception {
        mgr = new Manager();

    }
}
