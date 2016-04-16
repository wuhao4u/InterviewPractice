#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedListLib.h"

struct ListNode* BuildOneTwoThree() {
    struct ListNode* head = NULL;
    struct ListNode* second = NULL;
    struct ListNode* third = NULL;

    head = malloc(sizeof(struct ListNode));
    second = malloc(sizeof(struct ListNode));
    third = malloc(sizeof(struct ListNode));

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = NULL;

    return head;
}

struct ListNode* BuildByLength(int count){
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* cur = head;

    for (int i = 1; i < count; ++i)
    {
        cur->val = i;
        cur->next = malloc(sizeof(struct ListNode));
        cur = cur->next;
    }

    cur->val = count;
    cur->next = NULL;

    return head;
}

int Length(struct ListNode* head) {
    int count = 0;
    struct ListNode* current = head;

    while(current != NULL) {
        // printf("%d\n", current->val);
        current = current->next;
        count++;
    }

    return count;
}

void PrintList(struct ListNode* head) {
    int count = 0;
    struct ListNode* current = head;
    
    while(current != NULL) {
        printf("[%d]: %d\n", count, current->val);
        current = current->next;
        count++;
    }
}

void Push(struct ListNode** headRef, int val)
{
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    printf("headRef: %p\n", headRef);
    printf("*headRef: %p\n", *headRef);

    newNode->val = val;
    newNode->next = *headRef;

    *headRef = newNode;
}

struct ListNode* CopyList(struct ListNode* head)
{
    struct ListNode* current = head;
    struct ListNode* newList = NULL;
    struct ListNode* tail = NULL;

    while(current != NULL) {
        if(newList == NULL)
        {
            newList = malloc(sizeof(struct ListNode));
            newList->val = current->val;
            newList->next = NULL;
            tail = newList;
        }
        else
        {
            tail->next = malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->val = current->val;
            tail->next = NULL;
        }
        current = current->next;
    }
    return newList;
}

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* current = head;
    struct ListNode* reversed = NULL;
    struct ListNode* tail = NULL;

    while(current != NULL) {
        if(reversed == NULL)
        {
            reversed = malloc(sizeof(struct ListNode));
            reversed->val = current->val;
            reversed->next = NULL;
            tail = reversed;
        }
        else
        {
            reversed = malloc(sizeof(struct ListNode));
            reversed->val = current->val;
            reversed->next = tail;
            tail = reversed;
        }

        current = current->next;
    }
    return reversed;
}

void DeleteList(struct ListNode** headRef)
{
    struct ListNode* current = *headRef;
    struct ListNode* temp;

    while(current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *headRef = NULL;
}

int GetNth(struct ListNode* head, int index)
{

    struct ListNode* current = head;
    assert(index < Length(current));

    int i;
    for (i = 0; current != NULL; ++i, current = current->next)
    {
        if(i == index)
        {
            return current->val;
        }
    }
    printf("i is: %d\n", i);
    return -1;
}

int Count(struct ListNode* head, int element)
{
    int occurance = 0;
    struct ListNode* current = head;

    while(current != NULL) {
        if(current->val == element)
        {
            occurance++;
        }
        current = current->next;
    }
    return occurance;
}

// pop front
int Pop(struct ListNode** headRef)
{
    assert(*headRef != NULL);
    struct ListNode* head = *headRef;
    int headVal = head->val;
    *headRef = head->next;
    free(head);

    return headVal;
}
