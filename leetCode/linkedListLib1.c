#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"

struct ListNode* SortedMerge(struct ListNode* a, struct ListNode* b)
{
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while(1) {
        if(a == NULL) {
            tail->next = b;
            break;
        }
        else if(b == NULL) {
            tail->next = a;
            break;
        }
        else {
            if(a->val < b->val)
            {
                tail->next = a;
                tail = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                tail = b;
                b = b->next;                
            }
        }
    }

    return (dummy.next);
}