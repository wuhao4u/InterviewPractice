package net.wuhao4u;

/**
 * Created by wuhao on 2016-07-12.
 */
public class Solution238 {
    public int[] productExceptSelf(int[] nums) {
        int[] mult = new int[nums.length];
        mult[0] = 1;
        for(int i = 1; i < nums.length; ++i) {
            mult[i] = mult[i-1] * nums[i-1];
        }

        int factorial = 1;
        for(int j = nums.length-2; j >= 0; j--) {
            factorial *= nums[j+1];
            mult[j] *= factorial;
            int xx = 0;
        }
        return mult;
    }
}
