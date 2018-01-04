package net.wuhao4u;

public class CoinChange {

    // recursion + memo
    public static long makeChange(int[] coins, int money) {
        return makeChange(coins, money, 0);
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

    public static void main(String[] args) {
//        int[] coins = {25,10,5,1};
//        int total = 7;
//        System.out.println(CoinChange.makeChange(coins, total));

        int[] coins = {2,3,5,6};
        int total = 10;
        System.out.println(CoinChange.makeChange(coins, total));
     }
}
