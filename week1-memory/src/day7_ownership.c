#include <stdio.h>
#include <stdlib.h>

/* Function that allocates memory
   CALLER owns the returned memory */
int *create_number(int value) {
    int *ptr = malloc(sizeof(int));
    if (!ptr) return NULL;

    *ptr = value;
    return ptr;
}

/* Function that uses memory but DOES NOT free it */
void print_number(int *ptr) {
    if (!ptr) return;
    printf("Value: %d\n", *ptr);
}

/* Function that frees memory
   Ownership is transferred here */
void destroy_number(int *ptr) {
    free(ptr);
}

int main() {
    int *num = create_number(42);
    if (!num) return 1;

    print_number(num);

    destroy_number(num);
    num = NULL;  // prevent dangling pointer

    return 0;
}
