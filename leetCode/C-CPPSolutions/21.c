#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"


// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of the first two lists.

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;

    while(1) {
        if(l1 == NULL) {
            tail->next = l2;
            break;
        } else if(l2 == NULL) {
            tail->next = l1;
            break;
        } else {
            if(l1->val < l2->val) {                
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
        }
        tail = tail->next;
    }

    return dummy.next;
}

int main(int argc, char const *argv[]) {
    struct ListNode* test = BuildByLength(6);
    struct ListNode* test1 = BuildByLength(3);
    // PrintList(test);
    // PrintList(test1);

    PrintList(mergeTwoLists(test, test1));

    return 0;
}