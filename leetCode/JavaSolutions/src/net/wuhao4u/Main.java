package net.wuhao4u;

import java.util.Arrays;
import java.util.Random;

public class Main {

    public static void main(String[] args) {
        Solution289 sol = new Solution289();

        int[][] test = new int[2][2];
        test[0][0] = 0;
        test[0][1] = 1;
        test[1][0] = 1;
        test[1][1] = 1;
//        test[0][2] = 1;
//        test[0][3] = 0;
//
//        test[1][0] = 1;
//        test[1][1] = 1;
//        test[1][2] = 0;
//        test[1][3] = 1;
//
//        test[2][0] = 1;
//        test[2][1] = 0;
//        test[2][2] = 1;
//        test[2][3] = 1;


        //        Random ran = new Random();
//        int val = 0;
//
//        for(int r = 0; r<3; r++) {
//            for(int c = 0; c<4; c++) {
//                val = ran.nextInt(100);
//                test[r][c] = val < 50 ? 0 : 1;
//            }
//        }

        sol.gameOfLife(test);

        for(int r = 0; r < test.length; ++r) {
            System.out.println(Arrays.toString(test[r]));
        }
    }
}
