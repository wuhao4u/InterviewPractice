#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"

// Given a linked list, remove the nth node from the end of list and return its head.


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(n < 1)
        return head;

    int count = 0;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* cur = head;
    struct ListNode* remover = &dummy;

    while(cur != NULL) {
        if(count >= n)
            remover = remover->next;
        ++count;
        cur = cur->next;
    }

    if(count >= n) {
        remover->next = remover->next->next;
    }

    return dummy.next;
}

int main(int argc, char const *argv[]) {
    struct ListNode* test = BuildByLength(5);
    // PrintList(test);

    printf("---after removing\n");
    PrintList(removeNthFromEnd(test, 3));

    struct ListNode* test1;
    Push(&test1, 2);
    Push(&test1, 1);

    PrintList(test1);
    PrintList(removeNthFromEnd(test1, 2));

    return 0;
}