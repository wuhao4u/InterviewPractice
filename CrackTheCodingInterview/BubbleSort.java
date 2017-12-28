package net.wuhao4u;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class BubbleSort {
    private static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    private static int bubbleSort(int[] a) {
        int totalSwaps = 0;
        
        int curSwaps = 0;
        while (true) {
            curSwaps = 0;
            for (int i = 0; i < a.length - 1; ++i) {
                if (a[i] > a[i+1]) {
                    swap(a, i, i+1);
                    curSwaps++;
                }
            }
            
            if (curSwaps == 0) {
                return totalSwaps;
            } else {
                totalSwaps += curSwaps;
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n];
        for(int a_i=0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
        
        int count = bubbleSort(a);
        
        /*
            Array is sorted in 3 swaps.
            First Element: 1
            Last Element: 3        
        */
        
        System.out.printf("Array is sorted in %d swaps.\n", count);
        System.out.printf("First Element: %d\n", a[0]);
        System.out.printf("Last Element: %d\n", a[n-1]);
    }
}
