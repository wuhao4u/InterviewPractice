#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* delMe;

    if(head == NULL || head->next == NULL)
        return head;

    while(cur->next != NULL) {
        if(cur->next->val == cur->val) {
            delMe = cur->next;
            cur->next = cur->next->next;
        }
        else {
            cur = cur->next;            
        }
    }

    return head;
}

int main(int argc, char const *argv[]) {
    // struct ListNode* head = BuildByLength(9);
    // struct ListNode* newNode = malloc(sizeof(struct ListNode));
    // newNode->val = 5;
    // newNode->next = NULL;

    // SortedInsert(&head, newNode);

    struct ListNode* nn1 = malloc(sizeof(struct ListNode));
    nn1->val = 6;
    nn1->next = NULL;
    // SortedInsert(&head, nn1);

    // PrintList(head);
    
    // printf("---After Remove Duplicates\n");
    // deleteDuplicates(head);
    // PrintList(head);

    deleteDuplicates(nn1);
    PrintList(deleteDuplicates(nn1));

    struct ListNode* nn2;
    Push(&nn2, 2);
    Push(&nn2, 1);    
    PrintList(deleteDuplicates(nn2));


    // free(newNode);
    // free(nn1);
    return 0;
}