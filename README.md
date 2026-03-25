To get a true measurement of how your pragma affects the code, you need to compile this with a moderate level of optimization.

If you use `-O3` (maximum optimization), the compiler will probably unroll the loop anyway, so your pragma won't show a difference. If you use no optimization (`-O0`), the code will be artificially slow.

**`-O1` or `-O2` is the sweet spot for testing manual unrolling.**

If you are using GCC or Clang in your terminal, compile and run the baseline (without the pragma):

Bash

```
g++ benchmark.cpp -O1 -o benchmark
./benchmark
```

'-O1' '-O2' capital o not zero
