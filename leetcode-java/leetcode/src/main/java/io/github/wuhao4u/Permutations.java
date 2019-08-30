package io.github.wuhao4u;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;

public class Permutations {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        if (nums == null || nums.length == 0) {
            return res;
        }

        HashSet<Integer> used = new HashSet<>(nums.length);

        doPermute(nums, used, new ArrayList<Integer>(), res);
        return res;
    }

    private void doPermute(final int[] nums, HashSet<Integer> used,
                        List<Integer> soFar, List<List<Integer>> result) {
        if (soFar.size() >= nums.length) {
            System.out.println(soFar.toString());
            result.add(new ArrayList<>(soFar));
        }

        for (int i = 0; i < nums.length; ++i) {
            if (used.contains(nums[i])) continue;

            soFar.add(nums[i]);
            used.add(nums[i]);
            doPermute(nums, used, soFar, result);
            used.remove(nums[i]);
            soFar.remove(soFar.size() - 1);
        }
    }

    public static void main(String[] args) {
        Permutations solution = new Permutations();
        int[] a1 = {1,2,3};
        solution.permute(a1);
    }
}
