
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3; // initial size
    int *arr = malloc(n * sizeof(int));

    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // initialize array
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Resize array
    n = 5;
    int *temp = realloc(arr, n * sizeof(int));
    if (!temp) {
        printf("Reallocation failed\n");
        free(arr);
        return 1;
    }
    arr = temp;

    // initialize new elements
    for (int i = 3; i < n; i++) {
        *(arr+i) = (i + 1) * 10; // arr[i]==*(arr+i)=>pointer arithmetic
    }

    printf("Resized array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // free heap memory
    arr = NULL; // safe nullification

    return 0;
}

