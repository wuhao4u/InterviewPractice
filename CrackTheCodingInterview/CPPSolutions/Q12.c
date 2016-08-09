#include <stdio.h>
#include <stdlib.h>

/*
Implement a function void reverse(char* str) in C or C++
which reverses a null-terminated string.
*/

void swap(char* str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void reverse_hao(char* str) {
    char* init = str;
    char* tracker = str;
    int len = 0;

    while(str[len] != '\0') {
        tracker++;
        len++;
    }

    if(len < 2) return;

    for(int i = 0, j = len-1; i < j; i++, j--) {
        swap(str, i, j);
    }
}

// official solution
void reverse(char* str) {
    char* end = str;
    char tmp;
    if(str) {
        while(*end) {
            ++end; // find end of the string
        }
        --end; // set one char back, since last char is null

        // swap characters from start of string with the end pf the 
        // string, until the pointers meet in middle
        while(str < end) {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}

int main(int argc, char** argv) {
    char test[] = {'a', 'b', 'c', '\0'};
    printf("%s\n", test);
    reverse(test);
    printf("%s\n", test);
    return 0;
}