#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* aCur = headA;
    struct ListNode* bCur = headB;

    int aLen = Length(headA);
    int bLen = Length(headB);
    int dif = abs(aLen - bLen);

    if(aLen > bLen) {
        for (int i = 0; i < dif; ++i) {
            aCur = aCur->next;
        }
    } else {
        for (int i = 0; i < dif; ++i) {
            bCur = bCur->next;
        }
    }

    while(aCur != bCur) {
        aCur = aCur->next;
        bCur = bCur->next;
    }

    return bCur;
}

struct ListNode *getIntersectionNode_slow(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* aCur = headA;
    struct ListNode* bCur = headB;
    
    while(aCur != NULL) {
        while(bCur != NULL) {
            if(bCur == aCur)
            {
                return bCur;
            }
            bCur = bCur->next;
        }
        aCur = aCur->next;
        bCur = headB;
    }

    return NULL;
}

int main(int argc, char const *argv[]) {
    struct ListNode* a = BuildByLength(15);
    struct ListNode* b = BuildOneTwoThree();

    struct ListNode* bTail = b;
    struct ListNode* aMid = a;

    for (int i = 0; i < 10; ++i)
    {
        aMid = aMid->next;
    }

    while(bTail->next != NULL) {
        bTail = bTail->next;
    }
    bTail->next = aMid;

    printf("---A\n");
    PrintList(a);
    printf("---B\n");
    PrintList(b);

    printf("---\n");
    PrintList(getIntersectionNode(a, b));
    return 0;
}