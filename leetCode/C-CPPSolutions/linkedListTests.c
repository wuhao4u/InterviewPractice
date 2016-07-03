#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"
#include "linkedListTests.h"

void CountTest()
{
    struct ListNode* myList = BuildOneTwoThree();
    Push(&myList, 2);
    int count = Count(myList,2);
    printf("occurance of 2 is: %d\n", count);
}

void GetNthTest()
{
    struct ListNode* myList = BuildOneTwoThree();
    int lastNode = GetNth(myList, 2);

    printf("The 2nd index: %d\n", lastNode);

    printf("The 5th index: %d\n", GetNth(BuildByLength(5), 4));
}

void DeleteListTest()
{
    struct ListNode* myList = BuildOneTwoThree();
    Length(myList);
    DeleteList(&myList);
    printf("---After Delete\n");
    Length(myList);
}

void PopTest()
{
    struct ListNode* head = BuildByLength(3);
    printf("---Before Pop\n");
    Length(head);

    int a = Pop(&head);
    int b = Pop(&head);
    int c = Pop(&head);
    printf("---After Pop\n");
    int len = Length(head);

    printf("---Empty List Test\n");
    struct ListNode* emptyList = NULL;
    Pop(&emptyList);
}

void InsertNthTest()
{
    // struct ListNode* head = BuildByLength(6);
    struct ListNode* head = NULL;
    InsertNth(&head, 0, 0);
    InsertNth(&head, 1, 13);
    InsertNth(&head, 1, 42);
    InsertNth(&head, 1, 5);

    PrintList(head);

    DeleteList(&head);
}

void SortedInsertTest()
{
    struct ListNode* head = BuildByLength(10);
    struct ListNode* nNode = malloc(sizeof(struct ListNode));
    nNode->val = 3;
    nNode->next = NULL;

    struct ListNode testNode;
    testNode.val = 10;
    testNode.next = NULL;
    printf("---Before Insert\n");
    PrintList(head);
    SortedInsert(&head, nNode);
    SortedInsert(&head, &testNode);

    printf("---After Insert\n");
    PrintList(head);

    printf("---Insert in the end\n");
    struct ListNode* nNode1 = malloc(sizeof(struct ListNode));
    nNode1->val = 11;
    nNode1->next = NULL;
    SortedInsert(&head, nNode1);
    PrintList(head);

    printf("---Insert in the beginning\n");
    struct ListNode* nNode2 = malloc(sizeof(struct ListNode));
    nNode2->val  = -1;
    nNode2->next = NULL;
    SortedInsert(&head, nNode2);
    PrintList(head);
}

void InsertSortTest()
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
    InsertSort(&head);
    PrintList(head);
}

void AppendTest()
{
    // struct ListNode* a = BuildByLength(2);
    struct ListNode* a = NULL;
    struct ListNode* b = NULL;
    Push(&b, 4);
    Push(&b, 3);

    printf("---List A\n");
    PrintList(a);

    printf("---List B\n");
    PrintList(b);

    printf("---Appended B to A\n");
    Append(&a, &b);
    PrintList(a);
}

// front back split
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

    DeleteList(&head);
}

void SortedIntersectTest()
{
    // int primeNums[8] = {2, 3, 5, 7, 11, 13, 17, 19};
    struct ListNode* a;
    struct ListNode* b;
    
    int temp = 0;
    for (int i = 30; i > 0; --i)
    {
        temp = i%2;
        if(temp == 1)
        {
            Push(&a, i);
        }
    }

    Push(&b, 19);
    Push(&b, 17);
    Push(&b, 13);
    Push(&b, 11);
    Push(&b, 7);
    Push(&b, 5);
    Push(&b, 3);
    Push(&b, 2);

    PrintList(a);
    PrintList(b);

    printf("---Intersect Elements\n");
    PrintList(SortedIntersect(a, b));

    DeleteList(&a);
    DeleteList(&b);
}

void ReverseTest()
{
    struct ListNode* head;

    head = BuildByLength(10);
    PrintList(head);

    // Reverse(&head);
    // Reverse_hao(&head);
    RecursiveReverse(&head);

    // head now points to the list {3,2,1}
    printf("--After Reverse\n");
    PrintList(head);


    DeleteList(&head); // clean up after ourselves
}