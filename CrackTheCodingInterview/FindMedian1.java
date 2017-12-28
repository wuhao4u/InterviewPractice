/**************************************************************
 * 
 * 08-722 Data Structures for Application Programmers
 * Lab 7 Heaps and Java PriorityQueue class
 * 
 * Find median of integers using Heaps (maxHeap and minHeap)
 * 
 * Andrew id:  yuzhang
 * Name: Yu Zhang
 * 
 **************************************************************/

import java.util.*;

public class FindMedian_20150122 {
    private static PriorityQueue<Integer> maxHeap, minHeap;

    public static void main(String[] args) {
        // Or you can use Collections' reverseOrder method as follows.
        // Comparator<Integer> revCmp = Collections.reverseOrder();

        maxHeap = new PriorityQueue<Integer>(20, new Comparator<Integer>(){
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        
        minHeap = new PriorityQueue<Integer>(20);

        addNumber(6);
        addNumber(4);
        addNumber(3);
        addNumber(10);
        addNumber(12);
        System.out.println(minHeap);
        System.out.println(maxHeap);
        System.out.println(getMedian());

        addNumber(5);
        System.out.println(minHeap);
        System.out.println(maxHeap);
        System.out.println(getMedian());

        addNumber(7);
        addNumber(8);
        System.out.println(minHeap);
        System.out.println(maxHeap);
        System.out.println(getMedian());
    }

    /*
     * Note: it maintains a condition that maxHeap.size() >= minHeap.size()
     */
    public static void addNumber1(int value) {
        if (maxHeap.size() == minHeap.size()) {
            if (!maxHeap.isEmpty() && value > minHeap.peek()) {
                // put the new value in the right side.
                maxHeap.offer(minHeap.poll());
                minHeap.offer(value);
            } else {
                // add the new value into the left side.
                maxHeap.offer(value);
            }
        } else {
            if (value < maxHeap.peek()) {
                // add the new value into the left side.
                minHeap.offer(maxHeap.poll());
                maxHeap.offer(value);
            } else {
                // add the new value into the right side.
                minHeap.offer(value);
            }
        }
    }
    
    /*
     * Note: it maintains a condition that maxHeap.size() >= minHeap.size()
     * solution 2:
     */
    public static void addNumber(int value) {
        maxHeap.offer(value);
        
        // For this case, before insertion, max-heap has n+1 and min-heap has n elements.  
        // After insertion, max-heap has n+2 and min-heap has n elements, so violate!  
        // And we need to pop 1 element from max-heap and push it to min-heap  
        if (maxHeap.size() - minHeap.size() == 2) {
            // move one to the right side.
            minHeap.offer(maxHeap.poll());
        } else {
            if (minHeap.isEmpty()) {
                return;
            }
            
            // If the newly inserted value is larger than root of min-heap  
            // we need to pop the root of min-heap and insert it to max-heap.  
            // And pop root of max-heap and insert it to min-heap 
            if (minHeap.peek() < maxHeap.peek()) {
                // exchange the top value in the minHeap and the maxHeap.
                minHeap.offer(maxHeap.poll());
                maxHeap.offer(minHeap.poll());
            }
        }
    }

    /*
     * If maxHeap and minHeap are of different sizes, 
     * then maxHeap must have one extra element.
     */
    public static double getMedian() {
        if (maxHeap.isEmpty()) {
            return -1;
        }
        
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.peek();
        } else {
            return (double)(maxHeap.peek() + minHeap.peek()) / 2;
        }
    }
}