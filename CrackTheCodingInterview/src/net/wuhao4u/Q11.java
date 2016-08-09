package net.wuhao4u;

import java.util.HashMap;

/**
 * Created by wuhao on 2016-08-05.
 * Implement an algorithm to determine if a string has all unique characters.
 * WHat if you cannot use additional data structures?
 */
public class Q11 {
    public static boolean UniqueCharCheck(String mStr) {
        HashMap lookupTable = new HashMap();
        char c;
        for(int i = 0; i < mStr.length(); ++i) {
            c = mStr.charAt(i);
            if(lookupTable.get(c) != null) {
                return false;
            } else {
                lookupTable.put(c, 1);
            }
        }
        return true;
    }

    public static boolean UniqueCharCheckNoDS(String mStr) {
        for(int i = 0; i < mStr.length()/2 + 1; ++i) {
            for(int j = 0; j < mStr.length(); ++j) {
                if(j == i) continue;
                if(mStr.charAt(j) == mStr.charAt(i)) return false;
            }
        }
        return true;
    }

    // official solution
    public static boolean isUniqueChars(String str) {
        if (str.length() > 128) {
            return false;
        }
        boolean[] char_set = new boolean[128];
        for (int i = 0; i < str.length(); i++) {
            int val = str.charAt(i); // implicit cast?
            if (char_set[val]) return false;
            char_set[val] = true;
        }
        return true;
    }

    public static void main(String[] args) {
        String[] words = {"abcde", "hello", "apple", "kite", "padle"};
        for (String word : words) {
            System.out.println(word + ": " + isUniqueChars(word));
//            System.out.println(word + ": " + UniqueCharCheck(word));
//            System.out.println(word + ": " + UniqueCharCheckNoDS(word));
        }
    }
}
