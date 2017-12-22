import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    private static void reverse(int[] A, int l, int r) {
        int temp = 0;
        while(l < r) {
            temp = A[l];
            A[l] = A[r];
            A[r] = temp;
            
            ++l;
            --r;
        }
    }

    private static void leftRotate(int[] A, int n, int k) {
        if (A == null || A.length == 0) {
            return;
        }
        
        if (A.length > n || k > n) {
            return;
        }
        
        reverse(A, 0, k-1);        
        reverse(A, k, n-1);
        reverse(A, 0, n-1);
    }
    
    private static void printArray(int[] A) {
        if (A == null || A.length == 0) {
            return;
        }

        System.out.print(A[0]);
        for (int i = 1; i < A.length; ++i) {
            System.out.print(" ");
            System.out.print(A[i]);
        }
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int a[] = new int[n];
        for(int a_i=0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
        
        leftRotate(a, n, k);
        printArray(a);
    }
}
