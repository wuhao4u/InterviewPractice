#include <stdio.h>
#include <stdlib.h>

double getAverage(int* mList, int size) {
    double res;
    for(int i = 0; i < size; ++i) {
        res += mList[i];
    }

    return res / size;
}

double getAverage1(int mList[], int size) {
    double res;
    for(int i = 0; i < size; ++i) {
        res += mList[i];
    }

    return res / size;
}

int main(int argc, char const *argv[])
{
    int mListSize = 0;
    char c;
    printf("Enter size of the list: \n");
    scanf("%d", &mListSize);

    int mList[mListSize];
    printf("Enter elements: \n");

    for (int i = 0; i < mListSize; ++i) {
        scanf("%d", &mList[i]);
    }

    // printf("You entered: \n");
    // for (int i = 0; i < mListSize; ++i) {
    //     printf("%d\n", mList[i]);
    // }

    printf("Get average: %f\n", getAverage(mList, mListSize));
    printf("Get average1: %f\n", getAverage1(mList, mListSize));
    return 0;
}