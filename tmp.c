#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
     
    printf("--- For loop ---\n");
    
    int i = 0;
    
    for ( i = 0; i < 5; i++) {
        
        printf("index= %d\n", i);
    }

	return 0;
}