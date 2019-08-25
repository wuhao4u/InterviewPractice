package io.github.wuhao4u;

import java.util.Collections;

/**
 * Created by wuhao on 2016-07-06.
 * 26. Remove Duplicates from Sorted Array
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 */

public class Solution26 {
    // this solution credits to Mr. Hao Chen: https://github.com/haoel
    public int removeDuplicates(int[] nums) {
        if(nums.length <= 1) return nums.length;

        int pos = 0;
        for (int i = 0; i < nums.length-1; ++i) {
            if(nums[i] != nums[i+1]) {
                ++pos;
                nums[pos] = nums[i+1];
            }
        }

        return pos+1;
    }

    private static final void swap(int[] mArray, int i, int j) {
        int temp = mArray[i];
        mArray[i] = mArray[j];
        mArray[j] = temp;
    }

    public int removeDuplicatesSlow(int[] nums) {
        if(nums.length == 0) return 0;
        else if(nums.length == 1) return 1;

        // loop over all elements
        for(int i = 0; i < nums.length-1; ++i) {
            // find any ones
            for(int j = i+1; j < nums.length; ++j) {
                if(nums[j] == Integer.MAX_VALUE)
                    continue;
                else if(nums[j] == nums[i])
                    nums[j] = Integer.MAX_VALUE;
            }
        }

        int distinctCount = 0;

        // bubble sort, but is way too slow
        for(int x = 0; x < nums.length; ++x) {
            if(nums[x] == Integer.MAX_VALUE) {
                for(int y = x; y < nums.length; ++y) {
                    if(nums[y] < Integer.MAX_VALUE){
                        swap(nums, x, y);
                        break;
                    }
                }
            }
        }

        for(int z = 0; z < nums.length; ++z) {
            if(nums[z] == Integer.MAX_VALUE) break;
            ++distinctCount;
        }

        return distinctCount;
    }
}
