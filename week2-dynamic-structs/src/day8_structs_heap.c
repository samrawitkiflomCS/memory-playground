#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a simple person
typedef struct {
    char *name;
    int age;
} Person;

// Function to create a person (caller owns the memory)
Person *create_person(const char *name, int age) {
    Person *p = malloc(sizeof(Person));
    if (!p) return NULL;

    // Allocate memory for the name string
    p->name = malloc(strlen(name) + 1);
    if (!p->name) {
        free(p);
        return NULL;
    }
    strcpy(p->name, name);

    p->age = age;
    return p;
}

// Function to print person info (does NOT free memory)
void print_person(Person *p) {
    if (!p) return;
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

// Function to free a person struct (callee owns memory)
void destroy_person(Person *p) {
    if (!p) return;
    free(p->name);
    free(p);
}

int main() {
    // Create a person on the heap
    Person *alice = create_person("Alice", 25);
    if (!alice) return 1;

    print_person(alice);

    destroy_person(alice);
    alice = NULL; // avoid dangling pointer

    return 0;
}
