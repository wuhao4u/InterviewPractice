package net.wuhao4u;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by wuhao on 2016-07-03.
 */

public class Solution217 {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> occured = new HashSet<Integer>();
        for (Integer i : nums) {
            if (occured.contains(i)) {
                return true;
            } else {
                occured.add(i);
            }
        }
        return false;
    }
}
