#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

// Function to create a Person
Person create_person(const char *name, int age) {
    Person p;
    p.age = age;
    p.name = malloc(strlen(name) + 1);
        if (p.name != NULL) {
        strcpy(p.name, name);
    }
    return p;
}

// Function to free a Person
void destroy_person(Person *p) {
    if (!p) return;
    free(p->name);
    p->name = NULL;
}

int main() {
    int n = 3; // number of people
    Person *people = malloc(n * sizeof(Person));
    if (!people) return 1;

    // Initialize array
    people[0] = create_person("Alice", 25);
    people[1] = create_person("Bob", 30);
    people[2] = create_person("Charlie", 20);

    // Print array
    for (int i = 0; i < n; i++) {
        printf("Person %d: %s, Age: %d\n", i+1, people[i].name, people[i].age);
    }

    // Free nested allocations
    for (int i = 0; i < n; i++) {
        destroy_person(&people[i]);
    }

    // Free array itself
    free(people);
    people = NULL;

    return 0;
}
