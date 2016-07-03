/*
Given a linked list and a value x,
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"

struct ListNode* partition(struct ListNode* head, int x) {
    if(!head || !head->next) return head;

    struct ListNode* greaterThan = NULL;
    struct ListNode* gTracker = greaterThan;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* current = &dummy;

    while(current->next) {
        if(current->next->val >= x) {
            // move the next node to greaterThan list
            if(greaterThan) {
                gTracker->next = current->next;
                gTracker = gTracker->next;
            } else {
                greaterThan = current->next;
                gTracker = greaterThan;
            }

            current->next = current->next->next;
        } else {
            current = current->next;            
        }
    }

    if(gTracker) {
        gTracker->next = NULL;
        current->next = greaterThan;
    }

    return dummy.next;
}

int main(int argc, char const *argv[]) {
    // case 1, 1,4,3,2,5,2
    // struct ListNode* head;
    // Push(&head, 2);
    // Push(&head, 5);
    // Push(&head, 2);
    // Push(&head, 3);
    // Push(&head, 4);
    // Push(&head, 1);

    // case 2, NULL
    // struct ListNode* head;

    // case 3, 1 node
    // struct ListNode* head;
    // Push(&head, 1);

    // case 4, replicate, 1,1,1,2,2,2,3
    // struct ListNode* head;
    // Push(&head, 3);
    // Push(&head, 2);
    // Push(&head, 2);
    // Push(&head, 2);
    // Push(&head, 1);
    // Push(&head, 1);
    // Push(&head, 1);

    // case 5, 1,1
    // struct ListNode* head;
    // Push(&head, 1);
    // Push(&head, 1);

    // case 6, 2,1
    struct ListNode* head;
    Push(&head, 1);
    Push(&head, 2);

    PrintList(head);
    printf("---\n");
    PrintList(partition(head, 2));

    return 0;
}