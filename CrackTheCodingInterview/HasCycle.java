/*
Detect a cycle in a linked list. Note that the head pointer may be 'null' if the list is empty.

A Node is defined as: 
    class Node {
        int data;
        Node next;
    }
*/

// Way 2: 2 pointers
/*
fast = fast.next.next;
slow = slow.next;
*/

boolean hasCycle(Node head) {
    if (head == null) {
        return false;
    }
    
    Node fast = head;
    Node slow = head;
    
    while(fast.next != null && fast.next.next != null) {
        fast = fast.next.next;
        slow = slow.next;
        
        if (fast == slow) {
            return true;
        }
    }

    return false;
}