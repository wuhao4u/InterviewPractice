#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"

void FBSTest()
{
    struct ListNode* head = BuildByLength(1);
    struct ListNode* front = NULL;
    struct ListNode* back = NULL;

    FrontBackSplit(head, &front, &back);
    printf("---Front\n");
    PrintList(front);

    printf("---Back\n");
    PrintList(back);
}

void RemoveDuplicates(struct ListNode* head)
{
    struct ListNode* current = head;
    struct ListNode* temp = NULL;

    while(current->next != NULL) {
        if(current->val == current->next->val)
        {
            // remove the list
            temp = current->next;
            current->next = current->next->next;
            temp->next = NULL;
            free(temp);

            continue;
        }
        current = current->next;
    }
}

void RemoveDuplicatesTest()
{
    struct ListNode* head = BuildByLength(9);
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = 5;
    newNode->next = NULL;
    SortedInsert(&head, newNode);

    struct ListNode* nn1 = malloc(sizeof(struct ListNode));
    nn1->val = 6;
    nn1->next = NULL;
    SortedInsert(&head, nn1);

    PrintList(head);
    
    printf("---After Remove Duplicates\n");
    RemoveDuplicates(head);
    PrintList(head);

}

void MoveNodeTest()
{
    struct ListNode* a = BuildByLength(5);
    struct ListNode* b = BuildOneTwoThree();

    MoveNode(&a, &b);
    // MoveNode(&b, &a);

    printf("---After MoveNode\n---a\n");
    PrintList(a);
    printf("---b\n");
    PrintList(b);

    struct ListNode* dummy = NULL;
    MoveNode(&a, &dummy);
}

void AlternatingSplitTest()
{
    struct ListNode* head = BuildByLength(12);
    struct ListNode* a = NULL;
    struct ListNode* b = NULL;

    PrintList(head);
    AlternatingSplit(head, &a, &b);
    printf("---After Split\n---a\n");
    PrintList(a);
    printf("---b\n");
    PrintList(b);
}

void ShuffleMergeTest()
{
    struct ListNode* a = NULL;
    struct ListNode* b = BuildByLength(5);

    PrintList(ShuffleMerge_hao(a, b));
    // PrintList(ShuffleMerge(a, b));
}

struct ListNode* SortedMerge_cheap(struct ListNode* a,
 struct ListNode* b)
{
    assert(a != NULL || b != NULL);
    if(a == NULL)
    {
        InsertSort(&b);
        return b;
    }
    else if(b == NULL)
    {
        InsertSort(&a);
        return a;
    }
    else
    {
        // struct ListNode* result = a;
        Append(&a, &b);
        InsertSort(&a);
        return a;
    }
}

void SortedMergeTest()
{
    struct ListNode* a = BuildByLength(5);
    struct ListNode a1;
    a1.val = 8;
    a1.next = NULL;
    SortedInsert(&a, &a1);

    struct ListNode* b = BuildByLength(5);
    PrintList(SortedMerge(a, b));
}

void MergeSort(struct ListNode** headRef)
{
    // FrontBackSplit(), SortedMerge()
    // devide
    // if((*headRef)->next != NULL)
    // {

        struct ListNode* a = NULL;
        struct ListNode* b = NULL;
        FrontBackSplit(*headRef, &a, &b);
        if(Length(a) > 1)
            MergeSort(&a);
        if(Length(b) > 1)
            MergeSort(&b);
        *headRef = SortedMerge(a, b);
    // }
}

void MergeSortTest()
{
    // create an unsorted list
    struct ListNode* head = BuildByLength(10);
    Push(&head, 11);
    Push(&head, 5);
    InsertNth(&head, 2, 8);
    InsertNth(&head, 7, 0);
    InsertNth(&head, Length(head), -1);
    InsertNth(&head, Length(head), 4);
    PrintList(head);

    printf("---After sort\n");
    // sort
    MergeSort(&head);
    PrintList(head);

}

int main(int argc, char const *argv[])
{
    // FBSTest();
    // RemoveDuplicatesTest();
    // MoveNodeTest();
    // AlternatingSplitTest();
    // ShuffleMergeTest();
    // SortedMergeTest();
    MergeSortTest();
    return 0;
}