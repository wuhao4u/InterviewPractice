package io.github.wuhao4u;

import java.util.ArrayList;

/**
 * Created by wuhao on 2016-07-06.
 * 88. Merge Sorted Array
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 */
public class Solution88 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        ArrayList<Integer> placeHolder = new ArrayList<>(m+n);

        int i1, i2;
        i1 = i2 = 0;

        while (i1 < m && i2 < n) {
            if(nums1[i1] <= nums2[i2]) {
                placeHolder.add(nums1[i1]);
                ++i1;
            } else {
                placeHolder.add(nums2[i2]);
                ++i2;
            }
        }

        while (i1 < m) {
            placeHolder.add(nums1[i1]);
            ++i1;
        }

        while (i2 < n) {
            placeHolder.add(nums2[i2]);
            ++i2;
        }

        for(int k = 0; k < placeHolder.size(); ++k) {
            nums1[k] = placeHolder.get(k);
        }
    }

    private void arrayInsert(int[] mArray, int insertIndex, int insertVal) {
        for(int i = mArray.length-1; i > insertIndex; --i) {
            mArray[i] = mArray[i-1];
        }
        mArray[insertIndex] = insertVal;
    }

    public void merge_straight_insert(int[] nums1, int m, int[] nums2, int n) {
        int insertAnchor = 0;

        for(int i2 = 0; i2 < n; ++i2) {
            while (nums2[i2] >= nums1[insertAnchor] && insertAnchor < nums1.length){
                ++insertAnchor;
            }
            arrayInsert(nums1, insertAnchor, nums2[i2]);
        }
    }
}
