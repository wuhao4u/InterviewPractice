package net.wuhao4u;

public class Q18 {
    /*
     assume you have a method isSubstring which checks if one word is a substring of another.
     Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to
     isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").
    */
    private static boolean isRotation(String s1, String s2) {
        String s1s1 = s1.concat(s1);

        if (s1.length() == s2.length() && s1s1.contains(s2)) {
            return true;
        }

        return false;
    }


    public static void main(String[] args) {
        String s1 = "waterbottle";
        String s2 = "erbottlewat";

        System.out.println(Q18.isRotation(s1, s2));
    }
}
