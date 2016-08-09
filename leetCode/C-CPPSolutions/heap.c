#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "heap.h"

void Swap(int* myHeap, int i, int j) {
    int temp = myHeap[i];
    myHeap[i] = myHeap[j];
    myHeap[j] = temp;
}

int Parent (int* myHeap, int len, int index) {
    assert(index <= len);
    return myHeap[(index - 1) / 2];
}

int LeftChild(int* myHeap, int len, int index) {
    assert(index <= len);
    return myHeap[2*index + 1];
}

int RightChild(int* myHeap, int len, int index) {
    assert(index <= len);
    return myHeap[2*index + 2];
}

void SiftUp(int* myHeap, int len, int index) {
    int temp = -1;
    while(index > 0 && myHeap[Parent(myHeap, len, index)] < myHeap[index]) {
        // temp = myHeap[Parent(myHeap, len, index)];
        // myHeap[Parent(myHeap, len, index)] = myHeap[index];
        // myHeap[index] = temp;
        Swap(myHeap, Parent(myHeap, len, index), index);
        index = Parent(myHeap, len, index);
    }
}

void SiftDown(int* myHeap, int len, int index) {
    int maxIndex = index;
    int l = LeftChild(myHeap, len, index);

    if(l <= len && myHeap[l] > myHeap[maxIndex]) {
        maxIndex = l;
    }

    int r = RightChild(myHeap, len, index);

    if(r <= len && myHeap[r] > myHeap[maxIndex]) {
        maxIndex = r;
    }

    if(index != maxIndex) {
        Swap(myHeap, index, maxIndex);
        SiftDown(myHeap, len, maxIndex);
    }
}

void PrintHeap(int* myHeap, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", myHeap[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // tests code
    int len = 0;
    // int myArray[] = {42, 29, 18, 14, 7, 18, 12, 11, 5};
    int myArray[] = {1, 2, 3, 4, 5};

    // printf("How many elements in the heap: \n");
    // scanf("%d", &len);

    // myArray = malloc(len * sizeof(int));
    // for(int i = 0; i < len; ++i) {
    //     scanf("%d", &myArray[i]);
    // }

    printf("index?\n");
    int temp;
    scanf("%d", &temp);
    SiftDown(myArray, sizeof(myArray) / sizeof(myArray[0]), temp);
    PrintHeap(myArray, 5);

    return 0;
}