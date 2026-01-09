#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1 = malloc(sizeof(int));
    *ptr1 = 67;

    printf("Heap value: %d\n", *ptr1);

    int *ptr2 = malloc(sizeof(int));
    *ptr2 = 100;

    printf("New heap value: %d\n", *ptr2);

    free(ptr1);  // free the first allocation
    free(ptr2);  // free the second allocation

    return 0;
}

