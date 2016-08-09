package net.wuhao4u;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

/**
 * Created by wuhao on 2016-08-07.
 */
public class Q13 {
    private static void permutations(Set hs, String str) {
        permutations(hs, "", str);
    }

    private static void permutations(Set hs, String prefix, String str) {
        if(str.equals("")) {
//            System.out.println(prefix);
            hs.add(prefix);
        } else {
            // make each letter the first letter
            for(int i = 0; i < str.length(); ++i) {
                // TODO: understand this!
                permutations(hs, prefix + str.charAt(i),
                        str.substring(0, i) + str.substring(i+1, str.length()));
            }
        }
    }

    // official sol1, simply sort the two string. then sompare the two
    public String sort(String s) {
        char[] content = s.toCharArray();
        java.util.Arrays.sort(content);
        return new String(content);
    }

    public boolean permutation_sol1(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        return sort(s).equals(sort(t));
    }

    // Hao's solution. actually generate all of the permutation of one of the given string
    // takes longer compare to the official solution
    private static boolean isPermutation(String s1, String s2) {
        if(s1.length() != s2.length()) return false;
        Set permTable = new HashSet();
        permutations(permTable, s1);

        Iterator<String> val = permTable.iterator();
        String strHolder;

        while (val.hasNext()) {
            strHolder = val.next();
            if(strHolder.equals(s2)) return true;
        }

        return false;
    }

    public void main(String[] args) {
        System.out.println(isPermutation("god", "dog"));
        System.out.println(permutation_sol1("god", "dog"));

        System.out.println(isPermutation("god   ", "dog"));
        System.out.println(permutation_sol1("god   ", "dog"));
    }
}
