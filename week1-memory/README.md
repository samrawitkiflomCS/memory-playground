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
