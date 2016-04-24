#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedListLib.h"


int main(int argc, char const *argv[])
{
    struct ListNode* test = BuildByLength(6);
    PrintList();

    return 0;
}