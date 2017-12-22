import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class Solution {
    public static int numberNeeded(String s1, String s2) {
        if (s1 == null || s2 == null) return 0;
        if (s1.length() == 0 && s2.length() == 0) return 0;
        if (s1.length() == 0) return s2.length();
        if (s2.length() == 0) return s1.length();
        
        int[] f1 = new int[256];
        int[] f2 = new int[256];
        
        int index = 0;
        for (int i = 0; i < s1.length(); ++i) {
            index = (int) s1.charAt(i) - (int) 'a';
            f1[index] += 1;
        }

        for (int i = 0; i < s2.length(); ++i) {
            index = (int) s2.charAt(i) - (int) 'a';
            f2[index] += 1;
        }
        
        int res = 0;
        index = 0;
        while(index < f1.length) {
            res += Math.abs(f1[index] - f2[index]);
            index++;
        }
        return res;
    }
  
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a = in.next();
        String b = in.next();
        System.out.println(numberNeeded(a, b));
    }
}
