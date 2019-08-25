package io.github.wuhao4u;
import java.util.Arrays;

/**
 * Created by wuhao on 2016-07-12.
 Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 find the one that is missing from the array.

 For example,
 Given nums = [0, 1, 3] return 2.
 */
public class Solution268 {
    public int missingNumber(int[] nums) {
        int[] dup = new int[nums.length+1];

        for(int i = 0; i < nums.length; ++i) {
            dup[nums[i]] = 1;
        }

        int j = 0;
        for(j = 0; j < dup.length; ++j) {
            if(dup[j] == 0) return j;
        }
        return j;
    }
}
