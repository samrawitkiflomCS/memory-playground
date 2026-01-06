#include <stdio.h>
#include <stdlib.h>

int global_var = 100; // stored in global/static memory

int main() {
    int stack_var = 10;             // stored on the stack
    int *heap_var = malloc(sizeof(int)); // stored on the heap
    *heap_var = 20;

    printf("Global variable address: %p, value: %d\n", &global_var, global_var);
    printf("Stack variable address: %p, value: %d\n", &stack_var, stack_var);
    printf("Heap variable address: %p, value: %d\n", heap_var, *heap_var);

    free(heap_var); // always free heap memory
    return 0;
}
