#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"

struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;

    struct ListNode* sortedList = NULL;
    struct ListNode* current = head;

    struct ListNode* temp = NULL;
    while(current != NULL) {
        temp = current;

        if(sortedList == NULL) {
            Push(&sortedList, temp->val);
            // PrintList(sortedList);
        } else {
            // trace through the whole sorted list find the right spot
            int counter = 0;
            struct ListNode* sortedListCur = sortedList;
            while(sortedListCur != NULL && 
                sortedListCur->val < temp->val) {
                // printf("%d\t", sortedListCur->val);
                ++counter;
                sortedListCur = sortedListCur->next;
            }
            // printf("\nappend at %d\n", counter);

            InsertNth(&sortedList, counter, temp->val);
        }
        current = current->next;
    }

    return sortedList;
}

void insertionSortArray(int* mArray, int mArrayLen) {
    int holePostision = 0;
    int valueToInsert = 0;

    for(int i=1; i < mArrayLen; ++i) {
        // select value to be inserted
        valueToInsert = mArray[i];
        holePostision = i;

        while(holePostision > 0 && mArray[holePostision-1] > valueToInsert) {
            mArray[holePostision] = mArray[holePostision-1];
            --holePostision;
        }

        mArray[holePostision] = valueToInsert;
    }
}

int main(int argc, char const *argv[]) {
    struct ListNode* test = NULL;

    
    // Push(&test, 44);
    // Push(&test, 42);
    // Push(&test, 19);
    // Push(&test, 35);
    // Push(&test, 10);
    // Push(&test, 27);
    Push(&test, 33);
    Push(&test, 14);

    PrintList(test);
    printf("---after sort\n");
    PrintList(insertionSortList(test));
    

    int test1[8] = {14,33,27,10,35,19,42,44};
    insertionSortArray(test1, 8);

    printf("---after sort\n");
    for (int i = 0; i < 8; ++i) {
        printf("%d\n", test1[i]);
    }
    return 0;
}