string_maps_benchmark
=====================

Benchmarks of a different dictionary containers with string as key.
The goal was to find the best suitable data structure for fast file system searches.

We are using [hayai](https://github.com/nickbruun/hayai) as a C++ benchmarking framework.
Currently we have benchmarks for:
1. [Deschain / ART](https://github.com/Deschain/ART) - adaptive radix tree.
2. [Google's sparsehash/densehash](http://code.google.com/p/sparsehash/).
3. [Rasmus Ekman's Ternary Tree](http://www.abc.se/~re/code/tst/tst_docs/index.html).
4. [ytakano / radix_tree] (https://github.com/ytakano/radix_tree).
