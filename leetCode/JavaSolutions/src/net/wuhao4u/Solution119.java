package net.wuhao4u;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import static java.lang.Math.toIntExact;

/**
 * Created by wuhao on 2016-07-04.
 */
public class Solution119 {
    public List<Integer> getRow(int rowIndex) {
        if(rowIndex < 0) return null;

        ArrayList<Integer> result = new ArrayList<>();
        ArrayList<Integer> top = new ArrayList<>();

        if(rowIndex == 0) {
            result.add(1);
        } else if (rowIndex == 1) {
            result.add(1);
            result.add(1);
        } else {
            top.add(1);
            top.add(1);

            int curRow;
            for (curRow = 3; curRow < rowIndex+2; curRow++) {
                result = new ArrayList<>();
                // left most item
                result.add(1);

                // calculate middle elements based on top row
                for (int i = 0; i < top.size()-1; i++) {
                    result.add(top.get(i) + top.get(i+1));
                }

                // last element
                result.add(1);

                // shallow copy, increment top row for next loop
                top = result;
            }
        }

        return result;
    }

    // this answer calculates each individual element in the given row.
    // But the factorial will overflow after row 15 or so
    public List<Integer> getRow_partial(int rowIndex) {
        ArrayList<Integer> result = new ArrayList<>(rowIndex);
        long nominator = factorial(rowIndex);

        for(int i = 0; i <= rowIndex; ++i) {
            long res = nominator/(factorial(i) * factorial(rowIndex-i));
            result.add(toIntExact(res));
        }
        return result;
    }

    private long factorial(int x) {
        if (x <= 1) return 1;
        long res = 1;
        for(long i=x; i > 1; i--) {
            res *= i;
            System.out.println(res);
        }
        return res;
    }
}
