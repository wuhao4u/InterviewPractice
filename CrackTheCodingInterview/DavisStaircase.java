import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    // recursion without memoization, too slow
    private static int ways(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else if (n == 3) {
            return 4;
        } else {
            int w1 = ways(n-1);
            int w2 = ways(n-2);
            int w3 = ways(n-3);
            
            return w1 + w2 + w3;
        }
    }
    
    // build the table bottom up, much faster
    private static void waysBotUp(int[] knownWays) {
        knownWays[0] = 0;
        knownWays[1] = 1;
        knownWays[2] = 2;
        knownWays[3] = 4;
        
        for (int i = 4 ; i < knownWays.length; ++i) {
            knownWays[i] = knownWays[i-1] + knownWays[i-2] + knownWays[i-3];
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int s = in.nextInt();
        int[] knownWays = new int[37];
        waysBotUp(knownWays);

        for(int a0 = 0; a0 < s; a0++){
            int n = in.nextInt();
            System.out.println(knownWays[n]);
        }
    }
}
