# Week 1 — Memory in C

Goals for Week 1:
- Understand stack vs heap
- Write simple programs using malloc/free
- Introduce intentional memory bugs
- Learn to debug with Valgrind
- Document findings
 ## Day 2 — Stack vs Heap Memory

- Printed memory addresses of global, stack, and heap variables
- Observed that stack addresses are high and heap addresses are lower
- Freed heap memory correctly
- Verified no memory leaks using Valgrind

 ## Day 3 — Dangling Pointers & Undefined Behavior
- Observed different values when reading freed memory
- Learned that undefined behavior may appear to “work”
- Valgrind reliably detects invalid reads
- Nullifying the pointer is a good practice, it makes bugs easier to catch

 ## Day 4 — Double Free, NULL Safety & Segmentation Faults

- Experimented with **double free** and observed program crash:
  - free doesn't change where the pointer is pointing, it still points to the allocated memory
  - `free()` called twice caused: `double free detected in tcache 2`
  - Program aborted to protect memory integrity
- Learned that **free(NULL)** is safe and prevents crashes
- Triggered a **segmentation fault** by dereferencing a NULL pointer
- Valgrind confirmed invalid frees and memory errors
- Key takeaway: Always **nullify pointers after freeing** to prevent undefined behavior

 ## Day 5 — Memory Leaks & Losing Heap Ownership

- Demonstrated memory leak by losing pointer to allocated memory
- Valgrind detected 1 “definitely lost” block
- Fixed leak by keeping separate pointers and freeing all allocated memory
- Key takeaway: Always **track heap pointers** and free every allocation
- additional: valgrind outputs 3 allocs used, 2 free used eventhough we only used 2 allocs and 1 free
               - it's because of printf function which also allocates heap memory

 ## Day 6 — Dynamic Memory & Pointer Arithmetic

- Practiced dynamic arrays with malloc and realloc
   **realloc resizes heap memory and has three possible outcomes:
    In-place resize → pointer unchanged
    Moved block → pointer changes
    Failure → returns NULL, old pointer still valid
- Initialized and resized heap memory safely
- Used pointer arithmetic to access array elements
- Freed all allocated memory and nullified pointers
- Valgrind confirmed zero leaks or invalid accesses
 ## Day 7 — Memory Ownership & Function Boundaries

- Learned ownership rules in C
- Practiced allocating memory in one function and freeing in another
- Avoided double free and dangling pointers across function calls
- Used clear ownership transfer conventions
- Verified correctness with Valgrind
