/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedListLib.h"

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(m < 1 || !head) return head;

    struct ListNode dummy;
    dummy.next = head;
    dummy.val = 0;

    struct ListNode* current = &dummy;
    struct ListNode* reversedList = NULL;
    struct ListNode* rlTracker = NULL;

    struct ListNode* anchorHead = NULL;
    struct ListNode* anchorTail = NULL;

    int count = 0;
    while(current) {
        if(count == m - 1) {
            // keep track the pointer to the node before reversing
            anchorHead = current;
        }
        else if (count >= m && count <= n) {
            printf("push: %d\n", count);
            Push(&reversedList, current->val);
        }
        else if (count == n + 1) {
            anchorTail = current;
        }
        current = current->next;
        ++count;
    }

    if(count - 1 < n) {
        // printf("here\n");
        return head;
    }
    else {
        anchorHead->next = reversedList;
        struct ListNode* rlTail = reversedList;
        while(rlTail->next) {
            rlTail = rlTail->next;
        }
        rlTail->next = anchorTail;
    }

    return dummy.next;
}

int main(int argc, char const *argv[]) {
    struct ListNode* result;
    // case 1, 1,2,3,4,5; 2,4
    // struct ListNode* head = BuildByLength(5);
    // result = reverseBetween(head, 2, 4);

    // case 4, 1,2,3,4,5; 4,5
    // result = reverseBetween(head, 4,5);

    // case 5, 1,2,3,4,5; 1,5
    // result = reverseBetween(head, 1,2);

    // case 7, 1,2,3; 0, 2
    // struct ListNode* head = BuildOneTwoThree();
    // result = reverseBetween(head, 0,2);

    // case 8, 1,2,3; 1, 4
    // result = reverseBetween(head, 1,4);

    // case 2, 1,2; 1,2
    // struct ListNode* head = BuildByLength(2);
    // result = reverseBetween(head, 1, 2);

    // case 6, NULL; 1,2
    // struct ListNode* head = NULL;
    // result = reverseBetween(head, 1, 2);

    // case 3, 1; 1, 2
    struct ListNode* head;
    Push(&head, 1);
    result = reverseBetween(head, 1, 1);

    // PrintList(head);
    printf("---\n");
    PrintList(result);

    return 0;
}