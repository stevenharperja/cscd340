#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc == 1){
        printf("Usage: %s <num-mb>\n", argv[0]);
        return 1;
    }
    int num_mb = atoi(argv[1]);
    int size = num_mb * (1<<20);
    unsigned char *bytes = malloc(size);
    int i;
    while(1) {
        for(i = 0; i < size; i++) {
            bytes[i] = bytes[i % size] + 1;
        }
    }
    return 0;
}