package io.github.wuhao4u;

public class ReverseLinkedList {

    public ListNode reverseListRecursive(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode subListHead = reverseListRecursive(head.next);

        head.next.next = head;
        head.next = null;

        return subListHead;
    }



}
