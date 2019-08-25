package io.github.wuhao4u;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by wuhao on 2016-07-04.
 */
public class Solution66 {
    private static int numHelper(int i) {
        if(i == 9)
            return 0;
        else return i+1;
    }

    public  int[] plusOne(int[] digits) {
        List<Integer> resList = new ArrayList<Integer>();

        boolean carry = (digits[digits.length-1] == 9) ? true : false;
        resList.add(numHelper(digits[digits.length-1]));

        for (int i = digits.length-2; i >= 0; --i) {
            if(carry) {
                resList.add(0, numHelper(digits[i]));
                carry = (digits[i] == 9) ? true : false;
            } else {
                resList.add(0, digits[i]);
            }
        }

        if(carry) resList.add(0, 1);

        int[] result = new int[resList.size()];
        for(int j = 0; j < resList.size(); j++) {
            result[j] = resList.get(j);
        }

        return result;
    }


    public  int[] plusOne_bigint(int[] digits) {
        BigInteger num = BigInteger.ZERO;
        int power = 0;

        for(int i = digits.length-1; i>=0; i--) {
            long thisNum = (long)(digits[i] * Math.pow(10, power));
            BigInteger temp = BigInteger.valueOf(thisNum);
            num = num.add(temp);
            power++;
        }

        num = num.add(BigInteger.ONE);

        String resStr = num.toString();
        char[] resChar = resStr.toCharArray();

        int[] result = new int[resChar.length];
        for (int j = 0; j < resChar.length; j++) {
            result[j] = Character.getNumericValue(resChar[j]);
        }

        return result;
    }

    public int[] plusOne_int(int[] digits) {
        int num = 0;

        int power = 0;
        for(int i = digits.length-1; i >= 0; i--) {
            num += digits[i] * Math.pow(10, power);
            power++;
        }

        ++num;

        String resStr = Integer.toString(num);
        char[] resChar = resStr.toCharArray();

        int[] result = new int[resChar.length];
        for (int j = 0; j < resChar.length; j++) {
            result[j] = Character.getNumericValue(resChar[j]);
        }
        
        return result;
    }
}
