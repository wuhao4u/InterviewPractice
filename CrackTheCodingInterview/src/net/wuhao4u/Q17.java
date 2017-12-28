package net.wuhao4u;

import java.util.Arrays;

public class Q17 {
    private static void replaceRow(int[][] matrix, int row) {
        for (int c = 0; c < matrix[0].length; ++c) {
            matrix[row][c] = 0;
        }
    }

    private static void replaceCol(int[][] matrix, int col) {
        for (int r = 0; r < matrix.length; ++r) {
            matrix[r][col] = 0;
        }
    }

    private static void replaceWithZeros(int[][] matrix) {
        boolean[] zeroRows = new boolean[matrix.length];
        boolean[] zeroCols = new boolean[matrix[0].length];

        for (int r = 0; r < matrix.length; ++r) {
            for (int c = 0; c < matrix[0].length; ++c) {
                if (matrix[r][c] == 0) {
                    zeroRows[r] = true;
                    zeroCols[c] = true;
                }
            }
        }

        for (int i = 0; i < zeroRows.length; ++i) {
            if (zeroRows[i]) {
                replaceRow(matrix, i);
            }
        }

        for (int j = 0; j < zeroCols.length; ++j) {
            if (zeroCols[j]) {
                replaceCol(matrix, j);
            }
        }
    }

    public static void main(String[] args) {
        int[][] test = {
                {1,2,3},
                {4,4,6},
                {5,7,9},
                {6,0,6}
        };

        System.out.println(Arrays.deepToString(test));
        Q17.replaceWithZeros(test);
        System.out.println(Arrays.deepToString(test));
    }
}
