package net.wuhao4u;

import java.util.Arrays;

/**
 * Created by wuhao on 2016-08-09.
 */
public class Q16 {
    public static int[][] rotate90(int[][] m, int n) {
        int[][] rotated = new int[n][n];

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int nRow = c;
                int nCol = n - r - 1;

                rotated[nRow][nCol] = m[r][c];
            }
        }

        return rotated;
    }

    private static void swap(int[][] matrix, int r1, int c1, int r2, int c2) {

    }

    public static void rotate90InPlace(int[][] m, int n) {

    }

    public static void main(String[] args) {
        int[][] test = {
                {0,1,2,3},
                {4,5,6,7},
                {8,9,10,11},
                {12,13,14,15},
        };
        System.out.println(Arrays.deepToString(test));
        test = Q16.rotate90(test, test.length);
        System.out.println(Arrays.deepToString(test));
    }
}
