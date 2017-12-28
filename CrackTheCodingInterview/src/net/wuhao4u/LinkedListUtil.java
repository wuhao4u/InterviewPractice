package net.wuhao4u;

public class LinkedListUtil {
    public static Node arrayToLinkedList(int[] a) {
        Node dummy = new Node(-1);
        Node cur = dummy;

        for (int i = 0; i < a.length; ++i) {
            cur.next = new Node(a[i]);
            cur = cur.next;
        }

        return dummy.next;
    }

    public static void printLinkedList(Node head) {
        Node cur = head;

        System.out.print(cur.data);
        cur = cur.next;

        while (cur.next != null) {
            System.out.printf("->%d", cur.data);
            cur = cur.next;
        }
        System.out.println();
    }
}
