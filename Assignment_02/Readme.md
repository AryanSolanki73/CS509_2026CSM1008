# CS509 Laboratory Repository

## Assignment 02 – Bellman Ford and Floyd Warshall Algorithm Implementation

This is the Assignment 02 of **CS509 Laboratory** and have the following tasks inside it:

- **Task 01:** Implement Bellman Ford Algorithm
- **Task 02:** Implement Floyd Warshall Algorithm

---

# Assignment Structure

```text
Assignment_02
│
├── driver
│   └── main.cpp
│   
├── src
│   ├── bellmanFord.h
│   ├── bellmanFord.cpp
│   ├── floydWarshall.h
│   ├── floydWarshall.h
│   ├── csr.h
|   └── csr.cpp
│
├── Tests
│   ├── bf_10.txt
│   ├── bf_100.txt
│   ├── bf_10000.txt
│   ├── bf_50000.txt
│   ├── bf_100000.txt
|   ├── fw_10.txt
|   ├── fw_100.txt
|   ├── fw_500.txt
|   ├── fw_1000.txt
|   └── fw_2000.txt
|
├── Outputs
│   ├── bf_10.txt
│   ├── bf_100.txt
│   ├── bf_10000.txt
│   ├── bf_50000.txt
│   ├── bf_100000.txt
|   ├── fw_10.txt
|   ├── fw_100.txt
|   ├── fw_500.txt
|   ├── fw_1000.txt
|   └── fw_2000.txt
│
├── Makefile
└── Readme.md
```

---

# Tasks

## Task 02 – Bellman Ford Graph algo

Implementation of BellmanFord algorithm

## Task 02 – Floyd Warshall Graph Algo

Implements Floyd Warshall Algorithm

# Compilation & Execution

Navigate to the assignment directory.

```bash
cd CS509_2026CSM1008/common_wrapper
```

Compile the common wrapper.

```bash
g++ wrapper.cpp -o wrapper
```

Directory to run the wrapper
```bash
cd CS509_2026CSM1008/
```

Run the wrapper.

```bash
./common_wrapper/wrapper
```

The wrapper provides a menu-driven interface to:

- Compile individual tasks
- Execute a selected test case
- Execute all available test cases
- Clean generated binaries

---

# BellmanFord and Floyd-Warshall Result Table

| Algorithm | Test File | Vertices | Edges | Source | Negative cycle | Expected Output | Actual Output | Time | Status |
|---|---|---|---|---|---|---|---|---|---|
| Bellman-Ford | bf_10.txt | 10 | 30 | 0 | No | Distance | Distance | 0.00792 ms | ✅ Pass |
| Floyd-Warshall | fw_10.txt | 10 | N/A | N/A | No | Distance Matrix | Distance Matrix | 0.030783 ms | ✅ Pass |
| Bellman-Ford | bf_100.txt | 100 | 300 | 0 | No | Distance | Distance | 0.066169 ms | ✅ Pass |
| Floyd-Warshall | fw_100.txt | 100 | N/A | N/A | No | Distance Matrix | Distance Matrix | 34.6069 ms | ✅ Pass |
| Bellman-Ford | bf_10000.txt | 10000 | 30000 | 0 | No | Distance | Distance | 0.150342 ms | ✅ Pass |
| Floyd-Warshall | fw_500.txt | 500 | N/A | N/A | No | Distance Matrix | Distance Matrix | 2848.48 ms | ✅ Pass |
| Bellman-Ford | bf_50000.txt | 50000 | 150000 | 0 | No | Distance | Distance | 31.871 ms | ✅ Pass |
| Floyd-Warshall | fw_1000.txt | 1000 | N/A | N/A | No | Distance Matrix | Distance Matrix | 22942.2 ms | ✅ Pass |
| Bellman-Ford | bf_100000.txt | 100000 | 300000 | 0 | No | Distance | Distance | 80.4187 ms | ✅ Pass |
| Floyd-Warshall | fw_2000.txt | 2000 | N/A | N/A | No | Distance Matrix | Distance Matrix | 174670 ms | ✅ Pass |

---

---

# Performance Notes

Execution time measurements include **only the algorithm execution time**.

The following operations are **excluded** from the timing measurements:

- File reading
- Input parsing
- Matrix allocation and initialization
- Output generation
- CSR preprocessing (where applicable)

This follows the evaluation guidelines specified in the assignment document.

---

# Time & Space Complexity

## Task 01 – Bellman-Ford Algorithm

| Complexity | Value |
|------------|-------|
| Time | **O(V*E)** |
| Space | **O(V)** |

---

## Task 02 – Floyd-Warshall Algorithm

| Complexity | Value |
|------------|-------|
| Time | **O(V³)** |
| Space | **O(V²)** |

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