package net.wuhao4u;

import java.util.HashSet;

public class Q21 {
    /*
    Write code to remove duplicates from an unsorted linked list.
    FOLLOW UP
    How would you solve this problem if a temporary buffer is not allowed?
     */
    public static void removeDuplicates(Node head) {
        if (head == null) {
            return;
        }

        HashSet<Integer> set = new HashSet<>();
        Node dummy = new Node(-1);
        dummy.next = head;

        Node prev = dummy;
        Node cur = head;
        while (cur.next != null) {
            if (set.contains(cur.data)) {
                prev.next = cur.next;
                cur = cur.next;
            } else {
                set.add(cur.data);
                cur = cur.next;
                prev = prev.next;
            }
        }
    }

    public static void main(String[] args) {
        int[] a = {1, 2, 3, 4, 5, 6, 3, 4, 3, 2, 1, 9};
        Node test = LinkedListUtil.arrayToLinkedList(a);
        LinkedListUtil.printLinkedList(test);
        Q21.removeDuplicates(test);
        LinkedListUtil.printLinkedList(test);
    }
}
