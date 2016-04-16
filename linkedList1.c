#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* BuildOneTwoThree() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

struct node* BuildByLength(int count){
    struct node* head = malloc(sizeof(struct node));
    struct node* cur = head;

    for (int i = 0; i < count; ++i)
    {
        cur->data = i+1;
        cur->next = malloc(sizeof(struct node));
        cur = cur->next;
    }

    cur->data = count + 1;
    cur->next = NULL;

    return head;
}

int Length(struct node* head) {
    int count = 0;
    struct node* current = head;

    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
        count++;
    }
    return count;
}

void LengthTest() {
    struct node* myList = BuildByLength(5);

    int len = Length(myList);
}

struct node* LinkTest() {
    struct node* head = BuildByLength(5);

    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = 1;
    newNode->next = head;

    head = newNode;
    return head;
}

void Push(struct node** headRef, int data)
{
    struct node* newNode = malloc(sizeof(struct node));
    printf("headRef: %p\n", headRef);
    printf("*headRef: %p\n", *headRef);

    newNode->data = data;
    newNode->next = *headRef;

    *headRef = newNode;
}

struct node* CopyList(struct node* head)
{
    struct node* current = head;
    struct node* newList = NULL;
    struct node* tail = NULL;

    while(current != NULL) {
        if(newList == NULL)
        {
            newList = malloc(sizeof(struct node));
            newList->data = current->data;
            newList->next = NULL;
            tail = newList;
        }
        else
        {
            tail->next = malloc(sizeof(struct node));
            tail = tail->next;
            tail->data = current->data;
            tail->next = NULL;
        }
        current = current->next;
    }
    return newList;
}

struct node* CopyListWithPush(struct node* head)
{
    struct node* current = head;
    struct node* newList = NULL;
    struct node* tail = NULL;

    while(current != NULL) {
        if(newList == NULL)
        {
            Push(&newList, current->data);
            tail = newList;
        }
        else
        {
            Push(&(tail->next), current->data);
            tail = tail->next;
            tail->next = NULL;
        }        
        current = current->next;
    }
    return newList;
}

struct node* reverseList(struct node* head)
{
    struct node* current = head;
    struct node* reversed = NULL;
    struct node* tail = NULL;

    while(current != NULL) {
        if(reversed == NULL)
        {
            reversed = malloc(sizeof(struct node));
            reversed->data = current->data;
            reversed->next = NULL;
            tail = reversed;
        }
        else
        {
            reversed = malloc(sizeof(struct node));
            reversed->data = current->data;
            reversed->next = tail;
            tail = reversed;
        }

        current = current->next;
    }
    return reversed;
}

int main(int argc, char const *argv[])
{
    // struct node* mNode = BuildOneTwoThree();
    // Length(mNode);

    // struct node* mNode1 = BuildByLength();
    // Length(mNode1);
    // LengthTest();

    // struct node* mNode2 = NULL;
    // printf("%d\n", Length(mNode2));

    struct node* head = BuildByLength(6);
    printf("&head: %p\nhead: %p\n", &head, head);
    Length(head);

    printf("---\n");
    Push(&head, 0);
    Push(&head, 13);

    Length(head);
/*
    printf("---copy list\n");
    struct node* cHead = NULL;
    cHead = CopyList(head);
    Length(cHead); 

    printf("---copy list2\n");
    struct node* cHead1 = NULL;
    cHead1 = CopyListWithPush(head);
    Length(cHead1);
*/

    printf("---reversed\n");
    Length(reverseList(head));
    return 0;
}