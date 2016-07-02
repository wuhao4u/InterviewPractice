#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    while(i < numsSize) {
        if(nums[i] == val) {
            // remove item
            for (int j = i; j < numsSize; j++) {
                nums[j] = nums[j+1];
            }
            --numsSize;
        } else {
            ++i;
        }
    }
    return numsSize;
}

int main(int argc, char const *argv[]) {
    int test[] = {3,2,2,3};

    int removeVal = 2;
    int arraySize = 
    removeElement(test, sizeof(test)/sizeof(int), removeVal);

    for(int i = 0; i < arraySize; ++i) {
        printf("%d\n", test[i]);
    }

    return 0;
}