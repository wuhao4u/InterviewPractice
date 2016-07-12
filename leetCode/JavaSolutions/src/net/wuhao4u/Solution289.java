package net.wuhao4u;

import java.util.Arrays;

/**
 * Created by wuhao on 2016-07-08.
 */
public class Solution289 {
    private int countLiveNeighbors(int[][] board, int row, int col) {
        int res = 0;
        int rightBound = board[0].length - 1;
        int bottomBound = board.length - 1;

        if(board.length == 1) {
            if(col == 0 || col == rightBound) return 0;
            else
                return board[row][col-1] + board[row][col+1];
        } else if(board[0].length == 1) {
            if(row == 0 || row == bottomBound) return 0;
            else
                return board[row-1][col] + board[row+1][col];
        } else {
            if(row == 0) {
                if(col == 0) {
                    // top left
                    res += board[row][col+1];

                    res += board[row+1][col];
                    res += board[row+1][col+1];
                } else if (col == rightBound) {
                    // top right
                    res += board[row][col-1];

                    res += board[row+1][col-1];
                    res += board[row+1][col];

                } else {
                    res += board[row][col-1];
                    res += board[row][col+1];

                    res += board[row+1][col-1];
                    res += board[row+1][col];
                    res += board[row+1][col+1];
                }
            } else if (row == bottomBound) {
                if(col == 0) {
                    // bottom left
                    res += board[row-1][col];
                    res += board[row-1][col+1];

                    res += board[row][col+1];
                } else if(col == rightBound) {
                    // bottom right
                    res += board[row-1][col-1];
                    res += board[row-1][col];

                    res += board[row][col-1];
                } else {
                    res += board[row-1][col-1];
                    res += board[row-1][col];
                    res += board[row-1][col+1];

                    res += board[row][col-1];
                    res += board[row][col+1];
                }
            } else {
                if(col == 0) {
                    // left
                    res += board[row-1][col];
                    res += board[row-1][col+1];

                    res += board[row][col+1];

                    res += board[row+1][col];
                    res += board[row+1][col+1];
                } else if(col == rightBound) {
                    // right
                    res += board[row-1][col-1];
                    res += board[row-1][col];

                    res += board[row][col-1];

                    res += board[row+1][col-1];
                    res += board[row+1][col];
                } else {
                    res += board[row-1][col-1];
                    res += board[row-1][col];
                    res += board[row-1][col+1];

                    res += board[row][col-1];
                    res += board[row][col+1];

                    res += board[row+1][col-1];
                    res += board[row+1][col];
                    res += board[row+1][col+1];
                }
            }
        }
        return res;
    }

    public void gameOfLife(int[][] board) {
        if(board.length == 1 && board[0].length == 1) {
            board[0][0] = 0;
            return;
        } else if(board.length < 1) return;

        int[][] ori = new int[board.length][board[0].length];
        for(int i = 0; i < board.length; ++i) {
            ori[i] = Arrays.copyOf(board[i], board[i].length);
        }

        int cell = -1;
        for(int r = 0; r < ori.length; r++) {
            for(int c = 0; c < ori[r].length; c++) {
                cell = countLiveNeighbors(ori, r, c);
                if(cell == 2) {
                    continue;
                } else if(cell == 3) {
                    board[r][c] = 1;
                } else {
                    board[r][c] = 0;
                }
            }
        }
    }
}
