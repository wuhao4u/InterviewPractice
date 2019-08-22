package io.github.wuhao4u;

import static org.junit.jupiter.api.Assertions.*;

class SwapNodesInPairsTest {

    @org.junit.jupiter.api.Test
    void swapPairs() {
        ListNode one = new ListNode(1);
        ListNode two = new ListNode(2);
        ListNode three = new ListNode(3);
        ListNode four = new ListNode(4);

        one.next = two;
        two.next = three;
        three.next = four;

        SwapNodesInPairs solution = new SwapNodesInPairs();
        solution.swapPairs(one);
    }
}