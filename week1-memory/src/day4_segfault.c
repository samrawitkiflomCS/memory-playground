#include <stdio.h>

int main() {
    int *ptr = NULL;
    *ptr = 10;  //  segmentation fault
    return 0;
}
