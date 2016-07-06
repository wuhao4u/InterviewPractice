package net.wuhao4u;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by wuhao on 2016-07-05.
 */
public class Solution118 {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascalTri = new ArrayList<List<Integer>>();

        if(numRows <= 0){
            return pascalTri;
        }
        else if(numRows == 1) {
            ArrayList<Integer> row = new ArrayList<Integer>();
            row.add(1);
            pascalTri.add((List)row);
        } else if (numRows == 2) {
            ArrayList<Integer> row1 = new ArrayList<Integer>();
            row1.add(1);
            pascalTri.add((List)row1);

            ArrayList<Integer> row2 = new ArrayList<Integer>();
            row2.add(1);
            row2.add(1);
            pascalTri.add((List)row2);
        } else {
            ArrayList<Integer> row1 = new ArrayList<Integer>();
            row1.add(1);
            pascalTri.add((List)row1);

            ArrayList<Integer> top = new ArrayList<Integer>();
            top.add(1);
            top.add(1);
            pascalTri.add((List)top);

            ArrayList<Integer> curRow;
            for(int i = 3; i <= numRows; ++i) {
                curRow = new ArrayList<Integer>();
                curRow.add(1);
                for(int j = 0; j < top.size()-1; ++j) {
                    curRow.add(top.get(j) + top.get(j+1));
                }
                curRow.add(1);
                pascalTri.add(curRow);
                top = curRow;
            }
        }
        return pascalTri;
    }
}
