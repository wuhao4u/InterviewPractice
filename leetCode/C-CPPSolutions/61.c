#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedListLib.h"

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL) return head;

    struct ListNode dummy;
    dummy.next = head;
    dummy.val = -1;

    struct ListNode* current = head;
    struct ListNode* prev = &dummy;
    int count = 0;

    k = k % Length(head);
    if(k == 0) return head;

    while(current->next != NULL) {
        if(count >= k-1) {
            prev = prev->next;
        }
        current = current->next;
        ++count;
    }

    dummy.next = prev->next;
    current->next = head;
    prev->next = NULL;

    return dummy.next;
}

int main(int argc, char const *argv[]) {
    struct ListNode* test1 = BuildOneTwoThree();
    struct ListNode* test2 = BuildByLength(2);

    printf("---test1\n");
    PrintList(test1);

    printf("---test2\n");
    PrintList(test2);

    printf("---test1 rotated\n");
    PrintList(rotateRight(test1, 3));

    printf("---test2 rotated\n");
    PrintList(rotateRight(test2, 2));

    return 0;
}