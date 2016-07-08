package net.wuhao4u;

import java.util.Arrays;
import java.util.Random;

public class Main {

    public static void main(String[] args) {
        Solution26 sol = new Solution26();
        int[] test1 = {1,1,2};
        System.out.println(sol.removeDuplicates(test1));
        System.out.println(Arrays.toString(test1));

        int[] test2 = {1,1,1,2,3,3,3,0,0,0,0,0};
        System.out.println(sol.removeDuplicates(test2));
        System.out.println(Arrays.toString(test2));

        int[] test3 = {1,2};
        System.out.println(sol.removeDuplicates(test3));
        System.out.println(Arrays.toString(test3));
    }
}
