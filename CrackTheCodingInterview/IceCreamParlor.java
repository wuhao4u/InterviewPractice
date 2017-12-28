import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static void solve(int[] arr, int money) {
        // Complete this function
        HashMap<Integer, Integer> moneyMap = new HashMap<Integer, Integer>(arr.length);
        for (int i = 0; i < arr.length; ++i) {
            if (!moneyMap.containsKey(arr[i])) {
                moneyMap.put(arr[i], i);
            }
        }
        
        int remaining = -1;
        int k = -1;
        for (int j = 0; j < arr.length; ++j) {
            remaining = money - arr[j];
            if (moneyMap.containsKey(remaining)) {
                k = moneyMap.get(remaining);
                if (k != j) {
                    System.out.printf("%d %d\n", Math.min(k, j)+1, Math.max(k, j)+1);
                    return;
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int money = in.nextInt();
            int n = in.nextInt();
            int[] arr = new int[n];
            for(int arr_i = 0; arr_i < n; arr_i++){
                arr[arr_i] = in.nextInt();
            }
            solve(arr, money);
        }
        in.close();
    }
}
