#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"

bool hasCycle(struct ListNode *head) {
    struct ListNode* tortoise = head;
    struct ListNode* hare = head;
    
    while(tortoise && hare) {
        if(hare->next == NULL)
            return false;

        tortoise = tortoise->next;
        hare = hare->next->next;

        if(tortoise == hare)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    struct ListNode* head = BuildByLength(5);
    struct ListNode* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head->next;

    printf("has cycle? %d\n", hasCycle(head));
    return 0;
}