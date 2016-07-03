package net.wuhao4u;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by wuhao on 2016-07-03.
 */
public class Solution189 {
    public void rotate(int[] nums, int k) {
        if (k < 1 || nums.length <= 1) return;
        if (k > nums.length) k %= nums.length;

        int[] rotateHolder = new int[nums.length];
        int r = 0;
        for(int i = nums.length - k; i < nums.length; i++) {
            rotateHolder[r] = nums[i];
            ++r;
        }

        for(int j = 0; j < nums.length - k; j++) {
            rotateHolder[r] = nums[j];
            r++;
        }
        System.arraycopy(rotateHolder, 0, nums, 0, nums.length);
    }
}
