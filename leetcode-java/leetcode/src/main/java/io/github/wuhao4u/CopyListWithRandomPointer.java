package io.github.wuhao4u;

import java.util.HashMap;
import java.util.Map;

public class CopyListWithRandomPointer {
    class Node {
        public int val;
        public Node next;
        public Node random;

        public Node() {
        }

        public Node(int _val, Node _next, Node _random) {
            val = _val;
            next = _next;
            random = _random;
        }
    }

    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        // round 1
        // old to new map
        Map<Node, Node> onMap = new HashMap<>();
        Node dupHead = new Node(head.val, null, null);

        Node curr = head;
        Node dupCurr = dupHead;
        onMap.put(head, dupHead);

        while (curr != null && curr.next != null) {
            Node dupNext = new Node(curr.next.val, null, null);
            dupCurr.next = dupNext;

            onMap.put(curr.next, dupNext);

            curr = curr.next;
            dupCurr = dupCurr.next;
        }


        // round 2
        curr = head;
        dupCurr = dupHead;

        while (curr != null && dupCurr != null) {
            dupCurr.random = onMap.get(curr.random);

            curr = curr.next;
            dupCurr = dupCurr.next;
        }

        return dupHead;
    }

    // https://www.byte-by-byte.com/randomlinkedlist/
    // Copy list using extra space. Store mapping of old nodes to new nodes
    public Node cloneExtraSpace(Node n) {
        if (n == null) return n;

        // Map nodes in old list to equivalent nodes in new list
        HashMap<Node, Node> mapping = new HashMap<Node, Node>();

        // Create new linked list, minus the random node pointers. Save mapping
        // of equivalent old node to new node
        Node copy = new Node();
        Node nCurr = n, copyCurr = copy;
        mapping.put(nCurr, copyCurr);

        while (nCurr.next != null) {
            copyCurr.next = new Node();
            nCurr = nCurr.next;
            copyCurr = copyCurr.next;
            mapping.put(nCurr, copyCurr);
        }

        // Copy the random pointers. Find the random pointer in the original 
        // list and look up the equivalent using the map
        nCurr = n;
        copyCurr = copy;
        while (nCurr != null) {
            copyCurr.random = mapping.get(nCurr.random);
            nCurr = nCurr.next;
            copyCurr = copyCurr.next;
        }

        return copy;
    }

    // Copy list without using extra space. Interleave the nodes from the new 
    // with the nodes from the original list. Then separate the new list from the old
    public Node cloneNoExtraSpace(Node n) {
        if (n == null) return n;

        // Create new nodes in between the original nodes
        Node nCurr = n;
        while (nCurr != null) {
            Node temp = new Node();
            temp.val = nCurr.val;
            temp.next = nCurr.next;
            nCurr.next = temp;
            nCurr = nCurr.next.next;
        }

        // Copy random pointers
        nCurr = n;
        while (nCurr != null) {
            nCurr.next.random = nCurr.random.next;
            nCurr = nCurr.next.next;
        }

        // Separate new nodes from old nodes
        Node copy = n.next;
        nCurr = n;
        while (nCurr.next != null) {
            Node tmp = nCurr.next;
            nCurr.next = nCurr.next.next;
            nCurr = tmp;
        }

        return copy;
    }

    public static void main(String[] args) {
        Map<String, String> dict = new HashMap<>();
        dict.put("Hao", "Colleen");

    }
}
