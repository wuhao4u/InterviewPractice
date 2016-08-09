package net.wuhao4u;

/**
 * Created by wuhao on 2016-08-09.
 */
public class Q14 {
    public static void replaceWhitespace(char[] str, int len) {
        int whitespaceCount = 0;
        for(int i = 0; i < len; ++i) {
            if(str[i] == ' ') {
                whitespaceCount++;
            }
        }

        int bTracker = len - 1 + whitespaceCount * 2;
        for(int i = len-1; i >= 0; i--) {
            if(str[i] == ' ') {
                // replace ' ' with '%20'
                str[bTracker--] = '0';
                str[bTracker--] = '2';
                str[bTracker--] = '%';
            } else {
                // copy the char over
                str[bTracker] = str[i];
                bTracker--;
            }
        }
    }

    // official solution
    public void repaceSpaces(char[] str, int length) {
        int spaceCount = 0, newLength, i;

        // 1st loop, count the number of spaces
        for (i = 0; i < length; i++) {
            if (str[i] == ' ') {
                spaceCount++;
            }
        }

        // too replace ' ' with '%20', we need extra 2 spaces for every ' '
        newLength = length + spaceCount * 2;
        str[newLength] = '\0';

        // 2nd loop. going through the array reversely starting from the newLength
        for(i = length - 1; i >= 0; i--) {
            if(str[i] == ' ') {
                str[newLength - 1] = '0';
                str[newLength - 2] = '2';
                str[newLength - 3] = '%';
                newLength = newLength - 3;
            } else {
                str[newLength - 1] = str[i];
                newLength = newLength - 1;
            }
        }
    }

    public static void main(String[] args) {
        String test = "Mr John Smith        ";
        char[] testArray = test.toCharArray();

        System.out.println(testArray);
        replaceWhitespace(testArray, 13);
        System.out.println(testArray);
    }
}
