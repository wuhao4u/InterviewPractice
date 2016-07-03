#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.val = -1;
    dummy.next = head;
    struct ListNode* current = &dummy;

    struct ListNode* temp;
    while(current->next != NULL)
    {
        if(current->next->val == val)
        {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }

    return dummy.next;
}

int main(int argc, char const *argv[])
{
    struct ListNode* test = BuildByLength(6);
    PrintList(removeElements(test, 6));

    struct ListNode* test1;
    Push(&test1, 1);
    Push(&test1, 1);
    Push(&test1, 1);
    Push(&test1, 1);
    Push(&test1, 1);
    Push(&test1, 1);
    Push(&test1, 1);
    PrintList(removeElements(test1, 1));

    return 0;
}