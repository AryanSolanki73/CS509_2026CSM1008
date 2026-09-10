# CS509 Laboratory Repository

## Assignment 03 – MST Prims and Kruskal Algorithm Implementation

This is the Assignment 03 of **CS509 Laboratory** and have the following tasks inside it:

- **Task 02:** Implement MST Prims Algorithm
- **Task 02:** Implement MST Kruskal Algorithm

---

# Assignment Structure

```text
Assignment_02
│
├── driver
│   └── main.cpp
│   
├── src
│   ├── mst.h
|   ├── prims.cpp
│   ├── prims.cpp
│   ├── Kruskal.h
|   └── Kruskal.h
│
├── Tests
│   ├── mst_10.txt
│   ├── mst_100.txt
│   ├── mst_10000.txt
│   ├── mst_50000.txt
|   └── mst_100000.txt
|
├── Outputs
│   ├── mstp_10.txt
│   ├── mstp_100.txt
│   ├── mstp_10000.txt
│   ├── mstp_50000.txt
│   ├── mstp_100000.txt
|   ├── mstk_10.txt
|   ├── mstk_100.txt
|   ├── mstk_10000.txt
|   ├── mstk_50000.txt
|   └── mstk_100000.txt
│
├── Makefile
└── Readme.md
```

---

# Tasks

## Task 01 – Prims Minimum Spanning Tree Algorithm

Implementation of Prims Minimum spannig tree Algorithm

## Task 02 – Kruskal Minimum spanning tree Algorithm

Implementation of Kruskal Minimum spanning tree Algorithm

# Compilation & Execution

Navigate to the assignment directory.

```bash
cd CS509_2026CSM1008/common_wrapper
```

Compile the common wrapper.

```bash
make
```

Directory to run the wrapper (cd ..)
```bash
cd CS509_2026CSM1008/
```

Run the wrapper.

```bash
common_wrapper/wrapper
```

The wrapper provides a menu-driven interface to:
f
- Compile individual tasks
- Execute a selected test case
- Execute all available test cases
- Clean generated binaries

---

# Prims and Kruskal Result Table

## 9.1 MST Results Table

| File | V | E | Exp. Wt. | Kruskal Wt. | Prim Wt. | Kruskal Time | Prim Time | Equal? | Status |
|---|---:|---:|---:|---:|---:|---:|---:|:---:|:---:|
| `mst_10.txt` | 10 | 20 | 1963 | 1963 | 1963 | 0.020834 ms | 0.072665 ms | No | Pass |
| `mst_100.txt` | 100 | 200 | 23313 | 23313 | 23313 | 0.167891 ms | 0.602228 ms | No | Pass |
| `mst_10000.txt` | 10000 | 20000 | 2882810 | 2882810 | 2882810 | 13.9731 ms | 105.458 ms | No | Pass |
| `mst_50000.txt` | 50000 | 100000 | 14362765 | 14362765 | 14362765 | 72.0809 ms | 396.691 ms | No | Pass |
| `mst_100000.txt` | 100000 | 20000 | 28553310 | 28553310 | 28553310 | 167.908 ms | 860.882 ms | No | Pass |

---

---

# Performance Notes

Execution time measurements include **only the algorithm execution time**.

The following operations are **excluded** from the timing measurements:

- File reading
- Input parsing
- Output generation
- CSR preprocessing (where applicable)

This follows the evaluation guidelines specified in the assignment document.

---

# Time & Space Complexity

## Task 01 – Prims Algorithm

| Complexity | Value |
|------------|-------|
| Time | **O(ElogV)** |
| Space | **O(V + E)** |

---

## Task 02 – Kruskal's Algorithm

| Complexity | Value |
|------------|-------|
| Time | **O(ElogE)** |
| Space | **O(V + E)** |

# Technologies Used

- **Programming Language:** C++
- **Compiler:** GCC (g++)
- **Build System:** GNU Make
- **Platform:** Linux (WSL)
- **IDE:** Visual Studio Code
- **Version Control:** Git & GitHub

---

# References

1. Thomas H. Cormen, *Introduction to Algorithms*, 4th Edition.
2. GNU GCC Documentation.
3. GeeksforGeeks – Bellman-Ford and Floyd-Warshall webpages.
4. CS509 Laboratory Assignment Specification.

---