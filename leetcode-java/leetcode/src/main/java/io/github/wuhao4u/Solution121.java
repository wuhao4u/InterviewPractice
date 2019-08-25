package io.github.wuhao4u;
import java.util.ArrayList;
import java.util.Collections;

/**
 * Created by wuhao on 2016-07-03.
 */
public class Solution121 {
    public int maxProfit(int[] prices) {
        if (prices.length < 1) return 0;

        int prevMin = Integer.MAX_VALUE;
        prevMin = prices[0];

        int maxDif = 0;

        for(int i = 1; i < prices.length; i++) {
            if(prices[i] < prevMin) {
                prevMin = prices[i];
            } else if (prices[i] > prevMin) {
                int dif = prices[i] - prevMin;
                if(dif > maxDif) {
                    maxDif = dif;
                }
            }
        }
        return maxDif;
    }

    public int maxProfitSlow(int[] prices) {
        if (prices.length < 1) return 0;
        int maxDif = Integer.MIN_VALUE;
        ArrayList<Integer> previousElements = new ArrayList<Integer>();
        previousElements.add(prices[0]);

        for (int i = 1; i < prices.length; ++i) {
            int dif = prices[i] - Collections.min(previousElements);
            if(dif > 0) {
                if(dif > maxDif) maxDif = dif;
            }
            previousElements.add(prices[i]);
        }

        return maxDif > 0 ? maxDif : 0;
    }
}
