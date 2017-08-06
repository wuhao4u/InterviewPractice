#include <stdio.h>
// #include <stdlib.h>

void swap(int v[], int i, int j) {
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;

    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void print_int_array(int a[], int size) {
    for(int i = 0; i < size; ++i) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    int test[] = {5,4,2,3,1,6};
    // unsigned int testSize = sizeof(test)/sizeof(test[0]);
    int testSize = 6;

    print_int_array(test, testSize);
    qsort(test, 0, 6);
    print_int_array(test, testSize);

    return 0;
}