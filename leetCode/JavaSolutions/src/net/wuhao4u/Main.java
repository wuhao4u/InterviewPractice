package net.wuhao4u;

import java.util.Arrays;
import java.util.Random;

public class Main {

    public static void main(String[] args) {
        int[] test = {7, 1, 5, 3, 6, 4};
        int[] test1 = {7, 6, 4, 3, 1};
        int[] test2 = {};
        int[] test3 = {1,2,3,4,5,6,7};

        Solution189 sol = new Solution189();

        Random ran = new Random(System.currentTimeMillis());
        int mRan = ran.nextInt(test.length);
/*
        sol.rotate(test, mRan);
        System.out.println(mRan);
        System.out.println(Arrays.toString(test));

        mRan = ran.nextInt(test1.length);
        sol.rotate(test, mRan);
        System.out.println(mRan);
        System.out.println(Arrays.toString(test1));

//        sol.rotate(test, ran.nextInt(test2.length));
//        System.out.println(Arrays.toString(test2));

        int[] test4 = {-1};
        sol.rotate(test4, 2);
        System.out.println(Arrays.toString(test4));

        int[] test5 = {1, 2};
        sol.rotate(test5, 3);
        System.out.println(Arrays.toString(test5));
*/
        mRan = ran.nextInt(test3.length);
        sol.rotate(test3, 3);
        System.out.println(mRan);
        System.out.println(Arrays.toString(test3));
    }
}
