package net.wuhao4u;

import java.util.Arrays;
import java.util.Random;

public class Main {

    public static void main(String[] args) {
        Solution88 sol = new Solution88();
//        int[] test1 = {1,1,1,2,3,3,3,0,0,0,0,0};
//        int[] test2 = {5,6};
//        int[] test2 = {-1,0};

        int[] test1 = {1,2,4,5,6,0};
        int[] test2 = {3};
        sol.merge(test1, 5, test2, 1);
        System.out.println(Arrays.toString(test1));
    }
}
