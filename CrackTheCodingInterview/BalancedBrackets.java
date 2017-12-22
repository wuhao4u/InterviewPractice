import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    public static boolean isBalanced(String expression) {
        if (expression == null) return false;
        if (expression.length() == 0) {
            return true;
        }
        if (expression.length() % 2 != 0) {
            return false;
        }
        
        Stack<Character> stack = new Stack();
        
        char c;
        for (int i = 0; i < expression.length(); ++i) {
            c = expression.charAt(i);
            
            if (c == '(' || c == '[' || c == '{') {
                // push
                stack.push((Character) c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (stack.isEmpty()) {
                    return false;
                }
                
                // pop
                char left = stack.pop();
                if (c == ')' && left == '(') {
                    continue;
                }
                else if (c == ']' && left == '[') {
                    continue;
                }
                else if (c == '}' && left == '{') {
                    continue;
                }
                else {
                    return false;
                }
            } else {
                // invalid input
                return false;
            }
        }
        
        if (stack.isEmpty()) {
            return true;
        } else {
            return false;
        }
    }
  
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int a0 = 0; a0 < t; a0++) {
            String expression = in.next();
            System.out.println( (isBalanced(expression)) ? "YES" : "NO" );
        }
    }
}
