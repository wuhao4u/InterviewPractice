#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
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

void SortedInsert_hao(struct ListNode** headRef, struct ListNode* newNode)
{
    struct ListNode* current = *headRef;
    struct ListNode* previous = NULL;

    if(newNode->val < current->val)
    {
        Push(headRef, newNode->val);
        return;
    }

    while(current != NULL) {
        if(current->val > newNode->val) {
            newNode->next = current;
            previous->next = newNode;
            return;
        }
        previous = current;
        current = current->next;
    }

    // finally if is larger than all of the existing elements
    // insert the note in the end
    newNode->next = current;
    previous->next = newNode;
    // InsertNth(headRef, Length(*headRef), newNode->val);
}

void SortedInsert(struct ListNode** headRef, struct ListNode* newNode)
{
    if(*headRef == NULL || (*headRef)->val >= newNode->val)
    {
        // special case for the 1st node
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else
    {
        // Locate the node before the point of insertion
        struct ListNode* current = *headRef;
        while(current->next != NULL &&
         current->next->val < newNode->val)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// official answer, something's wrong here
void InsertSort(struct ListNode** headRef)
{
    struct ListNode* result = NULL;
    struct ListNode* current = *headRef;
    struct ListNode* next;

    while(current != NULL) {
        next = current->next;
        SortedInsert(&result, current);
        current = next;
    }

    *headRef = result;
}

void Append(struct ListNode** aRef, struct ListNode** bRef)
{
    if(*aRef == NULL)
    {
        *aRef = *bRef;
    }
    else
    {
        // regular cases
        struct ListNode* current = *aRef;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = *bRef;
    }
}

// split a list of nodes into 2 seperated lists
void FrontBackSplit(struct ListNode* source, 
    struct ListNode** frontRef, struct ListNode** backRef)
{
    int counter = 0;
    int len = Length(source);

    if(len % 2 == 0)
        len = len/2 - 1;
    else
        len = (len+1)/2 - 1;

    printf("1st half length: %d\n", len);

    *frontRef = source;
    struct ListNode* tracker = source;

    while(counter < len)
    {
        tracker = tracker->next;
        counter++;
    }

    *backRef = tracker->next;
    tracker->next = NULL;

}

void MoveNode(struct ListNode** destRef, struct ListNode** sourceRef)
{
    assert((*sourceRef) != NULL);
    struct ListNode* sHead = *sourceRef;
    *sourceRef = (*sourceRef)->next;

    sHead->next = *destRef;
    *destRef = sHead;
}

void AlternatingSplit(struct ListNode* source,
    struct ListNode** aRef, struct ListNode** bRef)
{
    struct ListNode* current = source;
    struct ListNode* temp;
    struct ListNode* aTracker;
    struct ListNode* bTracker;

    bool flag = true;

    while(current != NULL) {
        temp = current;
        current = current->next;
        temp->next = NULL;

        if(flag)
        {
            // add to a
            if(*aRef == NULL)
            {
                // spcial case for the beginning of a
                *aRef = temp;
                aTracker = *aRef;
            }
            else
            {
                aTracker->next = temp;
                aTracker = aTracker->next;
            }
        }
        else
        {
            // add to b
            if(*bRef == NULL)
            {
                // spcial case for the beginning of b
                *bRef = temp;
                bTracker = *bRef;
            }
            else
            {
                bTracker->next = temp;
                bTracker = bTracker->next;
            }
        }

        flag = !flag;
    }
    aTracker->next = NULL;
    bTracker->next = NULL;
}

struct ListNode* ShuffleMerge_hao(struct ListNode* a, struct ListNode* b)
{
    struct ListNode* result = NULL;
    struct ListNode* aTracker = a;
    struct ListNode* bTracker = b;
    struct ListNode* temp = NULL;
    bool flag = true;

    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;

    while(true)
    {
        if(flag)
        {
            if(aTracker->next != NULL)
            {
                temp = aTracker;
                aTracker = aTracker->next;
                temp->next = NULL;
                Append(&result, &temp);
            }
            else
            {
                temp = aTracker;
                Append(&result, &temp);
                Append(&result, &bTracker);
                return result;
            }
        }
        else
        {
            if(bTracker->next != NULL)
            {
                temp = bTracker;
                bTracker = bTracker->next;
                temp->next = NULL;
                Append(&result, &temp);
            }
            else
            {
                temp = bTracker;
                Append(&result, &temp);
                Append(&result, &aTracker);

                return result;
            }
        }
        flag = !flag;
    }
}

struct ListNode* ShuffleMerge(struct ListNode* a, struct ListNode* b) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while(1) {
        if(a == NULL) {
            tail->next = b;
            break;
        }
        else if(b == NULL) {
            tail->next = a;
            break;
        }
        else {
            tail->next = a;
            tail = a;
            a = a->next;
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }

    return (dummy.next);
}