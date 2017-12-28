import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    static final int[] neighborR = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    static final int[] neighborC = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    
    private static boolean inBounds(int r, int c, int[][] matrix) {
        if (r < 0 || r >= matrix.length) {
            return false;
        } else if (c < 0 || c >= matrix[0].length) {
            return false;
        } else {
            return true;
        }
    }
    
    private static void dfs(int startR, int startC, final int regionNum, int[][] regionMap, final int[][] matrix) {
        regionMap[startR][startC] = regionNum;
        
        for (int i = 0; i < neighborR.length; ++i) {
            int nr = startR + neighborR[i];
            int nc = startC + neighborC[i];

            if (!inBounds(nr, nc, matrix)) {
                continue;
            }

            if (regionMap[nr][nc] == 0 && matrix[nr][nc] == 1) {
                dfs(nr, nc, regionNum, regionMap, matrix);
            }
        }
    }

    private static void dfsWithStack(int startR, int startC, final int regionNum, 
                                     int[][] regionMap, final int[][] matrix) {        
        Stack<Integer> stackR = new Stack<Integer>();
        Stack<Integer> stackC = new Stack<Integer>();
        
        stackR.push(startR);
        stackC.push(startC);
        
        int curR, curC;
        while (!stackR.isEmpty()) {
            curR = stackR.pop();
            curC = stackC.pop();
            
            regionMap[curR][curC] = regionNum;

            for (int i = 0; i < neighborR.length; ++i) {
                int nr = curR + neighborR[i];
                int nc = curC + neighborC[i];

                if (!inBounds(nr, nc, matrix)) {
                    continue;
                }

                if (regionMap[nr][nc] == 0 && matrix[nr][nc] == 1) {
                    stackR.push(nr);
                    stackC.push(nc);
                }
            }
        }
    }
    
    public static int getBiggestRegion(int[][] matrix) {
        int[][] regionMap = new int[matrix.length][matrix[0].length];
        
        int regionNum = 1;
        for (int r = 0; r < matrix.length; ++r) {
            for (int c = 0; c < matrix[0].length; ++c) {
                if (matrix[r][c] == 0 || regionMap[r][c] != 0) {
                    continue;
                }

                dfs(r, c, regionNum++, regionMap, matrix);
            }
        }
        
        int[] regionCellNums = new int[regionNum];
        for (int r = 0; r < regionMap.length; ++r) {
            for (int c = 0; c < regionMap[0].length; ++c) {
//                System.out.printf("%d ", regionMap[r][c]);

                if (regionMap[r][c] != 0) {
                    regionCellNums[regionMap[r][c]-1]++;
                }
            }
//            System.out.println();
        }
        
        int maxCells = 0;
        for (int i = 0; i < regionCellNums.length; ++i) {
            maxCells = regionCellNums[i] > maxCells ? regionCellNums[i] : maxCells;
        }
        
        return maxCells;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int grid[][] = new int[n][m];
        for(int grid_i=0; grid_i < n; grid_i++){
            for(int grid_j=0; grid_j < m; grid_j++){
                grid[grid_i][grid_j] = in.nextInt();
            }
        }
        System.out.println(getBiggestRegion(grid));
    }
}
