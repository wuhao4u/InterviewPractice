#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"

struct ListNode* merge(struct ListNode* la, struct ListNode* lb);

struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL) return head;
    int len = Length(head);
    if(len <= 1) return head;

    struct ListNode* l1 = head;
    struct ListNode* l2 = head;
    int count = 1;
    while(count < (len/2)) {
        l2 = l2->next;
        ++count;
    }

    struct ListNode* temp = l2->next;
    l2->next = NULL;
    l2 = temp;

    // PrintList(l1);
    // PrintList(l2);
    l1 = sortList(l1);
    l2 = sortList(l2);

    return merge(l1,l2);
    // return NULL;
}

struct ListNode* merge(struct ListNode* la, struct ListNode* lb) {
    struct ListNode* result = NULL;
    struct ListNode* resCur = result;

    while(la != NULL && lb != NULL) {
        if (la->val > lb->val) {
            // add b to the result, remove from b
            if(!result) {
                result = lb;
                resCur = result;
            }
            else {
                resCur->next = lb;
                resCur = resCur->next;
            }
            lb = lb->next;
        } else {
            // add a to the resCur, remove from a
            if(!result) {
                result = la;
                resCur = result;
            }
            else {
                resCur->next = la;
                resCur = resCur->next;
            }
            la = la->next;
        }
    }

    while(la != NULL) {
        // add a to the end of theresCur 
        if(!result) {
            result = la;
            resCur = resCur->next;
        }
        else {
            resCur->next = la;
            resCur = resCur->next;
        }
        la = la->next;
    }

    while(lb != NULL) {
        // add b to the resCur, remove from b
        if(!result) {
            result = lb;
            resCur = result;
        }
        else {
            resCur->next = lb;
            resCur = resCur->next;
        }
        lb = lb->next;
    }
    resCur = NULL;

    return result;
}

int main(int argc, char const *argv[])
{
    struct ListNode* test1 = NULL;
    Push(&test1, 44);
    Push(&test1, 42);
    Push(&test1, 19);
    Push(&test1, 35);
    Push(&test1, 10);
    Push(&test1, 27);
    Push(&test1, 33);
    Push(&test1, 14);

    struct ListNode* test2 = BuildByLength(9);
    PrintList(test1);
    printf("---\n");
    struct ListNode* res = sortList(test1);
    printf("---\n");
    PrintList(res);

    return 0;
}