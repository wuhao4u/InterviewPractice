package io.github.wuhao4u;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class RecursionExamples {
    static void doPermute(final char[] in, StringBuilder out, int startIndex, List<String> results,
                          Set<Character> used) {

        if (startIndex == in.length) {
            // only record final results
            System.out.println(out.toString());
            results.add(out.toString());
            return;
        }

        for (int i = 0; i < in.length; ++i) {
            char c = in[i];

            if (used.contains(c)) continue;

            out.append(c);
            used.add(c);
            doPermute(in, out, startIndex + 1, results, used);
            used.remove(c);
            out.deleteCharAt(out.length() - 1);
        }
    }

    static void doCombine(final char[] in, StringBuilder out, int startIndex, List<String> results) {
        // record intermediate results, not just full-length
        System.out.println(out.toString());
        results.add(out.toString());

        for (int i = startIndex; i < in.length; ++i) {
            out.append(in[i]);

            doCombine(in, out, i + 1, results);

            out.deleteCharAt(out.length() - 1);
        }
    }

    //-----------------------------------------------------------------------------
    static void permute(String str) {
        if (null == str || str.length() == 0) return;

        char[] chars = str.toCharArray();
        List<String> results = new ArrayList<String>();

        doPermute(chars , new StringBuilder(), 0, results, new HashSet<Character>());
    }

    static void combine(String str) {
        if (str == null || str.length() == 0) return;

        char[] chars = str.toCharArray();
        Arrays.sort(chars);
        doCombine(chars, new StringBuilder(), 0, new ArrayList<String>());
    }

    public static void main(String[] args) {
        String s1 = "abcd";

        RecursionExamples.permute(s1);
        System.out.println("-----------------------------------------------------------------------------");
        RecursionExamples.combine(s1);
    }
}
