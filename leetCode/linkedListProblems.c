#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedListLib.h"

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

int main(int argc, char const *argv[])
{
    // CountTest();
    // GetNthTest();
    // DeleteListTest();
    // PopTest();
    // InsertNthTest();
    // SortedInsertTest();
    InsertSortTest();
    // AppendTest();

    return 0;
}