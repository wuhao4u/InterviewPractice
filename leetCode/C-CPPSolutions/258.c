#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int addDigits(int num)
{
    // if(num < 10 && num >= 0)
    //     return num;

    int sum = 0;
    while(num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    
    if(sum < 10 && sum >= 0)
        return sum;
    else
        return addDigits(sum);
}

int main(int argc, char const *argv[])
{
    time_t t;
    srand((unsigned) time(&t));

    int seed = 0;
    for (int i = 0; i < 5; ++i)
    {
        seed = rand() % 100;
        printf("[%d]: %d\n", seed, addDigits(seed));
    }
    printf("[%d]: %d\n", 19, addDigits(19));
    printf("[%d]: %d\n", 0, addDigits(0));
    return 0;
}