import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static class MyQueue<T> {
        Stack<T> not = new Stack<T>();
        Stack<T> oot = new Stack<T>();
        
        private void moveToOOT() {
            if (oot.empty()) {
                T temp;
                while(!not.empty()) {
                    temp = not.pop();
                    oot.push(temp);
                }
            }
        }
        
        public void enqueue(T value) { // Push onto newest stack
            if (value == null) {
                return;
            }
            
            not.push(value);
        }

        public T peek() {
            moveToOOT();
            if (oot.empty()) {
                return null;
            } else {
                return oot.peek();                
            }
        }

        public T dequeue() {
            moveToOOT();
            if (oot.empty()) {
                return null;
            } else {
                return oot.pop();                
            }
        }
    }

    
    public static void main(String[] args) {
        MyQueue<Integer> queue = new MyQueue<Integer>();
        
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        
        for (int i = 0; i < n; i++) {
            int operation = scan.nextInt();
            if (operation == 1) { // enqueue
                queue.enqueue(scan.nextInt());
            } else if (operation == 2) { // dequeue
                queue.dequeue();
            } else if (operation == 3) { // print/peek
                System.out.println(queue.peek());
            }
        }
        scan.close();
    }
}
