#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	printf("I am: %d\n", (int) getpid());
	return 0;
}
