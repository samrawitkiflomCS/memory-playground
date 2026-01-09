#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int));
    *ptr = 99;

    printf("Value before free: %d\n", *ptr);

    free(ptr);   // first free
    ptr =NULL;
    free(ptr);   //  safe, doe nothing

    return 0;
}
