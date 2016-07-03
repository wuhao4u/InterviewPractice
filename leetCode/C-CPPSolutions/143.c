#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedListLib.h"

void reorderListSlow(struct ListNode* head) {
    if(head == NULL || head->next==NULL) return;

    struct ListNode* cur = head;
    struct ListNode* tailTracer = cur;
    struct ListNode* temp = NULL;

    while(cur->next != NULL) {
        // move tail tracer to the node before last node
        tailTracer = cur;
        while(tailTracer->next->next != NULL) {
            tailTracer = tailTracer->next;
        }

        if(tailTracer == cur)
            break;

        temp = cur->next;
        cur->next = tailTracer->next;
        tailTracer->next = NULL;
        cur = cur->next;
        cur->next = temp;
    }
}

void reorderList(struct ListNode* head) {
    if(head == NULL || head->next==NULL) return;
    int len = Length(head);
    int mid = (len+1) / 2;
    struct ListNode* secondHalf = head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    for (int i = 0; i < mid; ++i) {
        prev = prev->next;
        secondHalf = secondHalf->next;
    }

    prev->next = NULL;
    Reverse_hao(&secondHalf);
    // PrintList(secondHalf);
    head = ShuffleMerge(head, secondHalf);
}

int main(int argc, char const *argv[]) {
    struct ListNode* test = BuildByLength(6);
    PrintList(test);

    printf("---\n");
    // reorderListSlow(test);
    reorderList(test);
    PrintList(test);
    return 0;
}