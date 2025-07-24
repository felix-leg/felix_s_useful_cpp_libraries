Commands instructing CPU directly.

* **prefetch**: Informs CPU that a data should (it is a hint, not a requirement) be moved into CPU's Cache for fast memory access.

**NOTE:** `prefetch` on GNU G++ requires `-masm=intel` to be added to compile command (see [`CMakeLists.txt`](CMakeLists.txt))
