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

void SortedInsert(struct ListNode** headRef, struct ListNode* newNode) {
    struct ListNode* current = *headRef;

    while(current != NULL) {
        if(newNode->val < current->next->val) {
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

void SortedInsertTest()
{
    struct ListNode* head = BuildByLength(10);
    struct ListNode* nNode = malloc(sizeof(struct ListNode));
    nNode->val = 3;
    nNode->next = NULL;
    printf("---Before Insert\n");
    PrintList(head);
    SortedInsert(&head, nNode);

    printf("---After Insert\n");
    PrintList(head);

}

int main(int argc, char const *argv[])
{
    // CountTest();
    // GetNthTest();
    // DeleteListTest();
    // PopTest();
    // InsertNthTest();
    SortedInsertTest();

    return 0;
}