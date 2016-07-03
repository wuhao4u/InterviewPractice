#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"

struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;


    struct ListNode dummy;
    dummy.next = head;
    dummy.val = -1;
    struct ListNode* cur = &dummy;
    // Push(&head, -1);
    // struct ListNode* cur = head;

    struct ListNode* temp;

    while(cur->next->next != NULL) {
        // swap
        temp = cur->next;
        cur->next = temp->next;
        temp->next = cur->next->next;
        cur->next->next = temp;

        cur = cur->next->next;
        if(cur->next == NULL)
            break;
    }

    return dummy.next;
    // return head->next;
}

int main(int argc, char const *argv[])
{
    struct ListNode* head = BuildByLength(4);
    PrintList(swapPairs(head));

    return 0;
}