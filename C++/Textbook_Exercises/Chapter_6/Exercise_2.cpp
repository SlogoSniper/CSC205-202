Both functions run and count for a while but recurse_forever ends up stopping eventually with a "segmentation fault".
This is because the runtime stack grows and shrinks when functions are called and then finished but with unlimited recursion,
functions keep getting called but never get finished so eventually the stack runs out of room.