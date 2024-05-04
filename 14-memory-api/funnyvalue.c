#include <stdio.h>
#include <stdlib.h>

int main()
{
 
    int* data = (int *) malloc(100 * sizeof(int));
    
    int* funny = data + 69; //its a low bar for humor here.

    free(funny);
 
    return 0;
}
