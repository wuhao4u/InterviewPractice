#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedListLib.h"

bool isPalindrome(struct ListNode* head) {
    struct ListNode* cpList = reverseList(head);
    struct ListNode* oCur = head;
    struct ListNode* cCur = cpList;

    while(oCur != NULL && cCur != NULL)
    {
        if(oCur->val != cCur->val)
            return false;

        oCur = oCur->next;
        cCur = cCur->next;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    struct ListNode* mList = BuildByLength(5);
    for (int i = 0; i < 6; ++i)
    {
        Push(&mList, i);
    }

    Length(mList);

    printf("%d\n", isPalindrome(mList));
    printf("%d\n", isPalindrome(BuildByLength(4)));

    return 0;
}