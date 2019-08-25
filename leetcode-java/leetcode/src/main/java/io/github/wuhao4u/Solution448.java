package io.github.wuhao4u;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by wuhao4u on 12/22/2016.
 */
public class Solution448 {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ret = new ArrayList<Integer>();

        for (int i = 0; i < nums.length; i++) {
            int val = Math.abs(nums[i]) - 1;
            if (nums[val] > 0) {
                nums[val] = -nums[val];
            }
        }

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                ret.add(i + 1);
            }
        }
        return ret;
    }

    public void test() {
        int[] test1 = {4, 3, 2, 7, 8, 2, 3, 1};
        int[] test2 = {1};
        System.out.println(this.findDisappearedNumbers(test1));
        System.out.println(this.findDisappearedNumbers(test2));
    }
}
