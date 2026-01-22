  ## Day 8 — Structs & Heap Memory

- Practiced dynamic structs allocation on the heap
- Managed nested allocations (string inside struct)
- Applied ownership rules: caller owns allocation, callee frees
- Ensured all memory is freed and pointers nullified
- Verified correctness with Valgrind
 ## Day 9 — Arrays of Structs & Heap Memory

- Allocated an array of structs dynamically on the heap
- Managed nested heap allocations for each struct
- Printed all elements safely
- Freed all nested allocations before freeing the array itself
- Nullified pointers to prevent dangling references
- Verified memory correctness with Valgrind
 ## Day 10 — Memory Playground: Combined Experiments

- Created array of heap pointers to structs
- Allocated nested memory for each struct member
- Resized array safely with realloc
- Printed all items before and after resizing
- Freed all nested allocations and the array itself
- Nullified all pointers to avoid dangling references
- Verified correctness and memory safety using Valgrind
