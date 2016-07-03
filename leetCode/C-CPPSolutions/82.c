// Given a sorted linked list, delete all nodes that have duplicate numbers, 
// leaving only distinct numbers from the original list.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode dummy;
    dummy.next = head;
    dummy.val = -1;
    struct ListNode* prev = &dummy;

    if(head == NULL || head->next == NULL) return head;

    while(cur->next) {
        if(cur->val != cur->next->val) {
            if(prev->next == cur)
                prev = prev->next;
            else {
                prev->next = cur->next;
            }
        }
        cur = cur->next;
    }

    if(prev->next != cur)
        prev->next = NULL;

    return dummy.next;
}

int main(int argc, char const *argv[]) {
    // case 1, 1,2,3,4,4,5
    struct ListNode* head = BuildByLength(5);
    InsertNth(&head, 4, 4);

    // case 2, 1,1,1,2,3,4
    // struct ListNode* head = BuildByLength(4);
    // Push(&head, 1);
    // Push(&head, 1);

    // case 3, 1,2,3,4,4,4
    // struct ListNode* head = BuildByLength(4);
    // InsertNth(&head, 4, 4);
    // InsertNth(&head, 5, 4);

    PrintList(head);
    printf("---\n");
    PrintList(deleteDuplicates(head));

    return 0;
}