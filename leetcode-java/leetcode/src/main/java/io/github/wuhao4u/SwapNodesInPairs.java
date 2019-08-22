package io.github.wuhao4u;

public class SwapNodesInPairs {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode second;
        second = head.next;

        head.next = second.next;
        second.next = head;

        head.next = this.swapPairs(head.next);
        return second;
    }

}
