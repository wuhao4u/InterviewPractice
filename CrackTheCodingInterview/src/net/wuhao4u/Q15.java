package net.wuhao4u;

import java.util.ArrayList;

/**
 * Created by wuhao on 2016-08-09.
 */
public class Q15 {
    public static String compressString(String oriStr) {
        if(oriStr.length() < 2) return oriStr;

        StringBuilder result = new StringBuilder();
        int counter = 1;

        result.append(oriStr.charAt(0));

        for(int i = 1; i < oriStr.length(); i++) {
            if(oriStr.charAt(i) == oriStr.charAt(i-1)) {
                counter++;
            } else {
                result.append(Character.forDigit(counter, 10));
                result.append(oriStr.charAt(i));
                counter = 1;
            }
        }
        result.append(Character.forDigit(counter, 10));

        if(result.length() >= oriStr.length())
            return oriStr;

        return result.toString();
    }

    static String compressBetter(String str) {
        // check if compression would create a longer string
        int size = countCompression(str);
        if (size >= str.length()) {
            return str;
        }

        StringBuffer mystr = new StringBuffer();
        char last = str.charAt(0);
        int count = 1;
        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) == last) {
                count++;
            } else {
                mystr.append(last);
                mystr.append(count);
                last = str.charAt(i);
                count = 1;
            }
        }

        mystr.append(last);
        mystr.append(count);
        return mystr.toString();
    }

    // go through the string and calculate how long the compressed string will be
    static int countCompression(String str) {
        if(str == null || str.isEmpty()) return 0;
        char last = str.charAt(0);
        int size = 0;
        int count = 1;
        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) == last) {
                count++;
            } else {
                last = str.charAt(i);
                // 1 is the char itself, plus the length of the count number itself(it could be 2,3)
                size += 1 + String.valueOf(count).length();
                count = 1;
            }
        }
        size += 1 + String.valueOf(count).length();
        return size;
    }

    public static void main(String[] args) {
        String test = "aabcccccaaa";
        System.out.println(compressString(test));
        System.out.println(compressBetter(test));

        test = "a";
        System.out.println(compressString(test));
        System.out.println(compressBetter(test));

        test = "";
        System.out.println(compressString(test));
        System.out.println(compressBetter(test));

        test = "aaa";
        System.out.println(compressString(test));
        System.out.println(compressBetter(test));

        test = "ab";
        System.out.println(compressString(test));
        System.out.println(compressBetter(test));
    }
}
