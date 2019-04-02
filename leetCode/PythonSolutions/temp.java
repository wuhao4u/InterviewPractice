public class Solution {
    /**
     * @param tree: The type of fruit
     * @return: The total amount of fruit you can collect.
     */
    public int totalFruit(int[] tree) {
        // write your code here
        int res = 0, cur = 0, count_b = 0, a = 0, b = 0;
        for (int c :  tree) {
            cur = c == a || c == b ? cur + 1 : count_b + 1;
            count_b = c == b ? count_b + 1 : 1;
            if (b != c) {a = b; b = c;}
            res = Math.max(res, cur);
        }
        return res;
    }
}



public class Solution {
    /**
     * @param tree: The type of fruit
     * @return: The total amount of fruit you can collect.
     */
    public int totalFruit(int[] tree) {
        // write your code here
        int res = 0, cur = 0, count_b = 0, a = 0, b = 0;
        for (int c : tree) {
            if (c == a || c == b) {
                // increment cur counter
                cur = cur + 1;
            } else {
                // increment the other counter
                cur = count_b + 1;
            }

            if (c == b) {
                count_b = count_b + 1;
            } else {
                // init the counter b
                count_b = 1;
            }           

            if (b != c) {
                a = b;
                b = c;
            }

            res = Math.max(res, cur);
        }
        return res;
    }
}