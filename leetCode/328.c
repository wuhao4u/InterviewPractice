#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedListLib.h"

struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head) return head;
    if(!head->next) return head;

    bool flag = true;
    struct ListNode* current = head;
    struct ListNode* oddHead = current;
    struct ListNode* evenHead = current->next;
    current = current->next;

    struct ListNode* eTracker = evenHead;
    struct ListNode* oTracker = oddHead;

    while(current->next != NULL) {
        if(flag) {
            oTracker->next = current->next;
            oTracker = oTracker->next;
        } else {
            eTracker->next = current->next;
            eTracker = eTracker->next;
        }

        current = current->next;
        flag = !flag;
    }
    eTracker->next = NULL;
    oTracker->next = evenHead;

    return oddHead;
}

int main(int argc, char const *argv[])
{
    // test case 1: normal
    // struct ListNode* head = BuildByLength(11);
    // test case 2: 0 element    
    // struct ListNode* head = NULL;
    // test case 3: 1 ele
    // struct ListNode* head = BuildByLength(1);
    // test case 4: 2 ele, 1,2
    // struct ListNode* head = BuildByLength(2);
    // test case 5: 3 ele, 1,2,3
    // struct ListNode* head = BuildByLength(3);
    // test case 5: 4 ele, 1,2,3,4
    struct ListNode* head = BuildByLength(4);

    Length(head);

    printf("---odd even list\n");
    struct ListNode* oeHead = oddEvenList(head);

    PrintList(oeHead);

    return 0;
}