#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* tortoise = head;
    struct ListNode* hare = head;

    while(hare && tortoise) {
        if(hare->next == NULL) return NULL;
        
        tortoise = tortoise->next;
        hare = hare->next->next;

        if(tortoise == hare)
            break;
    }

    if (hare != tortoise)
        // there is no cycle exist in this list
        return NULL;
    else {
        // has the cycle, find the cycle starting point
        tortoise = head;
        while(tortoise != hare) {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        return tortoise;
    }
}

int main(int argc, char const *argv[])
{
    struct ListNode* head = BuildByLength(2);
    struct ListNode* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head->next;

    if(detectCycle(head) == NULL)
        printf("no cycle found!\n");
    else
        printf("%d\n", (detectCycle(head))->val);

    head = BuildByLength(2);
    if(detectCycle(head) == NULL)
        printf("no cycle found!\n");
    else
        printf("%d\n", (detectCycle(head))->val);

    return 0;
}