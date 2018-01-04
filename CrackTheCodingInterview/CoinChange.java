import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    // recursion + memo
    public static long makeChange(int[] coins, int money) {
        makeChange(coins, money, 0);
    }

    private static long makeChange(int[] coins, int money, int index) {
        // base case 1: we do get 0 remaining
        if (money == 0) {
            return 1;
        }

        // base case 2: we used up all the coins
        if (index >= coins.length) {
            return 0;
        }

        int amountWithCoin = 0;
        long ways = 0;
        while (amountWithCoin <= money) {
            int remaining = money - amountWithCoin;
            ways += makeChange(coins, remaining, index + 1);
            amountWithCoin += coins[index];
        }

        return ways;
    }


    // Interative
    public static long makeChange(int[] coins, int amount) {
        long[] combinations = new long[amount+1];

        // base case
        combinations[0] = 1;
        
        // with first coin, first 2 coins, first 3 coins...
        // how many combinations we have using first x coins
        for (int coin : coins) {
            for (int i = 1; i < combinations.length; ++i) {
                if (i >= coin) {
                    combinations[i] += combinations[i - coin];
                }
            }
        }
        return combinations[amount];
    }
  
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int coins[] = new int[m];
        for(int coins_i=0; coins_i < m; coins_i++){
            coins[coins_i] = in.nextInt();
        }
        
//        Arrays.sort(coins);
        System.out.println(makeChange(coins, n));
    }
}
