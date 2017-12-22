import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    private static boolean canPrint(String[] mags, String[] rans) {
        if (mags == null || rans == null) return false;
        if (mags.length < rans.length) return false;
        
        HashMap<String, Integer> dict = new HashMap<String, Integer>();
        int appearance = 0;
        for (String s : mags) {
            if (dict.containsKey(s)) {
                appearance = dict.get(s);
                dict.put(s, appearance + 1);
            } else {
                dict.put(s, 1);
            }
        }
        

        for (String s : rans) {
            appearance = dict.get(s);
            
            if (appearance <= 0) {
                return false;
            }
            
            dict.put(s, appearance - 1);
        }
        
        return true;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int n = in.nextInt();
        String magazine[] = new String[m];
        for(int magazine_i=0; magazine_i < m; magazine_i++){
            magazine[magazine_i] = in.next();
        }
        String ransom[] = new String[n];
        for(int ransom_i=0; ransom_i < n; ransom_i++){
            ransom[ransom_i] = in.next();
        }
        
        if (canPrint(magazine, ransom)) {
            System.out.print("Yes");
        } else {
            System.out.print("No");
        }
    }
}
