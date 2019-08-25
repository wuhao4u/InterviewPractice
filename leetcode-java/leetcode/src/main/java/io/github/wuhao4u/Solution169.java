package io.github.wuhao4u;
import java.util.HashMap;

/**
 * Created by wuhao on 2016-07-03.
 */
public class Solution169 {

    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> occurances = new HashMap<Integer, Integer>();

        for (Integer i: nums) {
            if(occurances.get(i) == null) {
                occurances.put(i, 1);
                if(1 > nums.length / 2)
                    return i;
            } else {
                int iOccur = occurances.get(i);
                ++iOccur;
                occurances.replace(i, iOccur);
                if(iOccur > nums.length / 2)
                    return i;
            }
        }

        return -1;
    }
}
