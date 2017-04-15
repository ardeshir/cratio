#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
   
    int i;

    printf("Not a shell anymore! My pid= %d\n", getpid());
    printf("\n");

    for (i = 0; i < argc; i++)
       printf("Args[%d] = \"%s\"\n", i, argv[i]);

    exit(EXIT_SUCCESS);
}

