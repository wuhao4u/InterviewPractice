#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"

struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* oddPtr = head;

    for(int i = 0; current != NULL; ++i, current = current->next)
    {
        if(i % 2 == 1)
        {
            // these are even numbers, needs to move to cur
            printf("i mod 2 == 1 val: %d\n", current->val);
        }

    }
    return head;
}

int main(int argc, char const *argv[])
{
    struct ListNode* head = BuildByLength(10);
    Length(head);

    printf("---odd even list\n");
    struct ListNode* oeHead = oddEvenList(head);

    Length(oeHead);

    return 0;
}