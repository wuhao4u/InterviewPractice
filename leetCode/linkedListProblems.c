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

void InsertNth(struct ListNode** headRef, int index, int data)
{
    int len = Length(*headRef);
    assert(index <= len);

    int count = 1;
    struct ListNode* current = *headRef;

    if (index == 0)
    {
        // special case
        Push(headRef, data);
    }
    else
    {
        // regular case
        while(current != NULL) {
            if(count == index) {
                // insert the node
                struct ListNode* newNode = malloc(sizeof(struct ListNode));
                newNode->val = data;
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
            count++;
        }
    }
}

void InsertNthTest()
{
    struct ListNode* head = BuildByLength(6);

    InsertNth(&head, 1, 13);
    InsertNth(&head, 1, 42);
    InsertNth(&head, 1, 5);

    PrintList(head);

    DeleteList(&head);
}

int main(int argc, char const *argv[])
{
    // CountTest();
    // GetNthTest();
    // DeleteListTest();
    // PopTest();
    InsertNthTest();

    return 0;
}