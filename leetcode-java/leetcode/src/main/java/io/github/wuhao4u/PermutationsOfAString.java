package io.github.wuhao4u;

public class PermutationsOfAString {
    // permute string
    public void permute(String str) {
        int length = str.length();
        boolean[] used = new boolean[length];
        StringBuilder out = new StringBuilder();
        char[] in = str.toCharArray();

        doPermute(in, out, used, length, 0);
    }

    private void doPermute(final char[] in, StringBuilder out, boolean[] used, final int length, int level) {
        if (level == length) {
            System.out.println(out.toString());
            return;
        }

        for(int i = 0; i < length; ++i) {
            if (used[i]) continue;

            out.append(in[i]);
            used[i] = true;
            doPermute(in, out, used, length, level + 1);
            used[i] = false;
            out.setLength(out.length() - 1);
        }
    }

    public static void main(String[] args) {
        PermutationsOfAString solution = new PermutationsOfAString();
        solution.permute("abcd");
    }
}
