/*
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "linkedListLib.h"

#define MAX_LEN 255

void reverse(char *string) 
{
   int length, c;
   char *begin, *end, temp;
 
   // printf("before reverse: %s\n", string);
   length = strlen(string);
   begin  = string;
   end    = string;
 
   for (c = 0; c < length - 1; c++)
      end++;
 
   for (c = 0; c < length/2; c++)
   {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }

   // printf("after reverse: %s\n", string);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = NULL;
    struct ListNode* rT = result;
    struct ListNode* current = NULL;
    char num1Char[MAX_LEN], num2Char[MAX_LEN];
    unsigned long num1 = 0, num2 = 0, resInt = 0;
    char *ptr;
    // int num1 = 0, num2 = 0, resInt = 0;

    current = l1;
    int count = 0;
    while(current != NULL) {
        num1Char[count] = current->val + '0';
        current = current->next;
        count++;
    }
    num1Char[count] = '\0';
    reverse(num1Char);
    num1 = strtol(num1Char, &ptr, 10);
    // printf("num1: %lu\n", num1);


    current = l2;
    count = 0;
    while(current != NULL) {
        num2Char[count] = current->val + '0';
        current = current->next;
        count++;
    }
    num2Char[count] = '\0';
    reverse(num2Char);
    num2 = strtol(num2Char, &ptr, 10);
    // printf("num2: %lu\n", num2);

    resInt = num1 + num2;
    // printf("resInt: %lu\n", resInt);

    if(resInt == 0) {
        result = malloc(sizeof(struct ListNode));
        result->val = 0;
        result->next = NULL;
    } else if(resInt == num1) {
        return l1;
    }  else if(resInt == num2) {
        return l2;
    }

    while(resInt != 0) {
        if(result == NULL) {
            result = malloc(sizeof(struct ListNode));
            result->val = resInt % 10;
            rT = result;
        } else {
            rT->next = malloc(sizeof(struct ListNode));
            rT = rT->next;
            rT->val = resInt % 10;
        }
        rT->next = NULL;
        resInt /= 10;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    // case 1
    struct ListNode* head1;
    struct ListNode* head2;
    // Push(&head1, 3);
    // Push(&head1, 4);
    // Push(&head1, 2);

    // Push(&head2, 4);
    // Push(&head2, 6);
    // Push(&head2, 5);


    // case 2, 0, 0
    // Push(&head1, 0);
    // Push(&head2, 0);

    // case 3, 1, 1
    // Push(&head1, 1);
    // Push(&head2, 1);

    // case 4, 00010, 00020
    // Push(&head1, 0);
    // Push(&head1, 1);
    // Push(&head1, 0);
    // Push(&head1, 0);

    // Push(&head2, 0);
    // Push(&head2, 2);
    // Push(&head2, 0);
    // Push(&head2, 0);

    // case 5, [9], [1,9,9,9,9,9,9,9,9,9]
    Push(&head2, 9);

    Push(&head1, 9);
    Push(&head1, 9);
    Push(&head1, 9);
    Push(&head1, 9);
    Push(&head1, 9);
    Push(&head1, 9);
    Push(&head1, 9);
    Push(&head1, 9);
    Push(&head1, 9);
    Push(&head1, 1);

    // case 6, [1,8], [0]
    // Push(&head1, 8);
    // Push(&head1, 1);
    // Push(&head2, 0);

    // case 7, [8, 9], [1], [9, 9]
    // Push(&head1, 8);
    // Push(&head1, 9);
    // Push(&head2, 1);

    // case 8, [9, 8], [1], [0, 9]
    // Push(&head1, 8);
    // Push(&head1, 9);
    // Push(&head2, 1);

    printf("---head 1\n");
    PrintList(head1);
    printf("---head 2\n");
    PrintList(head2);
    printf("---added\n");
    PrintList(addTwoNumbers(head1, head2));

    // int a = 6;
    // char c = a + '0';
    // printf("%c\n", c);
    return 0;
}