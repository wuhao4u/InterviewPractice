package io.github.wuhao4u;

public class CombinationsOfAString {
    /*
    For each letter from input start position to end of input string
        Select the letter into the current position in output string
        Print letters in output string
        If the current letter isn't the last in the input string
    Generate combinations starting at next position with iteration starting
    at next letter beyond the letter just selected
     */

    void combine(String str) {
        int length = str.length();
        char[] instr = str.toCharArray();
        StringBuilder outstr = new StringBuilder();

        doCombine(instr, length, outstr, 0, 0);
    }

    void doCombine(final char[] instr, final int length,
                   StringBuilder outstr,
                   int level, int start) {
        for (int i = start; i < length; ++i) {
            outstr.append(instr[i]) ;
            System.out.println(outstr);

            if (i < length - 1) {
                doCombine(instr, length, outstr, level + 1, i + 1);
            }

            outstr.deleteCharAt(outstr.length() - 1);
        }
    }

    public static void main(String[] args) {
        CombinationsOfAString solution = new CombinationsOfAString();
        solution.combine("wxyz");
    }
}
