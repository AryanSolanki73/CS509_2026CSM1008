# CS509 Laboratory Repository

## Assignment 01 – General Matrix Multiplication (GEMM) & CSR Graph

This assignment is a part of the **CS509 Laboratory** coursework and consists of the following individual tasks:

- **Task 01:** Simple General Matrix Multiplication (GEMM)
- **Task 02:** Blocking (Tiled) General Matrix Multiplication
- **Task 03:** Compressed Sparse Row (CSR) Graph Conversion

---

# Assignment Structure

```text
Assignment_01
│
├── Task_01
│   ├── driver/
│   ├── src/
│   ├── tests/
│   ├── outputs/
│   └── Makefile
│
├── Task_02
│   ├── driver/
│   ├── src/
│   ├── tests/
│   ├── outputs/
│   └── Makefile
│
├── Task_03
│   ├── driver/
│   ├── src/
│   ├── tests/
│   ├── outputs/
│   └── Makefile
│
├── common_wrapper.cpp
└── README.md
```

---

# Tasks

## Task 01 – Simple General Matrix Multiplication (GEMM)

Implements the conventional three-loop General Matrix Multiplication algorithm.

### Features

- Standard matrix multiplication
- Dynamic matrix input
- Execution time measurement

---

## Task 02 – Blocking (Tiled) General Matrix Multiplication

Implements blocked (tiled) matrix multiplication to improve cache locality and execution performance.

### Features

- Loop blocking (Tiling)
- Cache-aware implementation
- Performance comparison with Simple GEMM

---

## Task 03 – Compressed Sparse Row (CSR) Graph Conversion

Converts a graph stored as an adjacency list into the **Compressed Sparse Row (CSR)** representation.

### Features

- Sparse graph representation
- Efficient memory usage
- CSR preprocessing
- CSR row pointer and column index generation

---

# Compilation & Execution

Navigate to the assignment directory.

```bash
cd Assignment_01/common_wrapper
```

Compile the common wrapper.

```bash
g++ wrapper.cpp -o wrapper
```

Directory to run the wrapper
```bash
cd Assignment_01/
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

# GEMM Result Table

| Test File | Input Size | Expected Output | Actual Output | Simple GEMM Time | Blocking GEMM Time | Block Size | Status |
|-----------|------------|-----------------|---------------|-----------------:|-------------------:|-----------:|:------:|
| test_01.txt | 4 × 4 | Result Matrix | Result Matrix | 0.067044 ms | 0.003044 ms | 2 | ✅ Pass |
| test_02.txt | 10 × 10 | Result Matrix | Result Matrix | 0.03409 ms | 0.023559 ms | 2 | ✅ Pass |
| test_03.txt | 100 × 100 | Result Matrix | Result Matrix | 25.2415 ms | 14.039 ms | 32 | ✅ Pass |
| test_04.txt | 250 × 250 | Result Matrix | Result Matrix | 245.845 ms | 252.054 ms| 32 | ✅ Pass |
| test_05.txt | 500 × 500 | Result Matrix | Result Matrix | 1834.88 ms | 2016.93 ms | 32 | ✅ Pass |
| test_06.txt | 1000 × 1000 | Result Matrix | Result Matrix | 15888.1 ms | 15697.1 ms | 32 | ✅ Pass |

> **Note:** The input matrices used for `test_02.txt` and `test_03.txt` differ between the **Simple GEMM** and **Blocking GEMM** implementations. Therefore, they are listed separately.

---

# CSR Graph Result Table

| Test File | Input Type | Expected Output | Actual Output | Conversion Time | Status |
|-----------|------------|-----------------|---------------|----------------:|:------:|
| test_01.txt | Graph (V = 5, E = 6) | CSR Representation | CSR Representation | 0.002982 ms | ✅ Pass |
| test_02.txt | Graph (V = 10, E = 20) | CSR Representation | CSR Representation | 0.003786 ms | ✅ Pass |
| test_02.txt | Graph (V = 100, E = 300) | CSR Representation | CSR Representation | 0.014355 ms | ✅ Pass |
| test_02.txt | Graph (V = 500, E = 2000) | CSR Representation | CSR Representation | 0.050382 ms | ✅ Pass |
| test_02.txt | Graph (V = 1000, E = 5000) | CSR Representation | CSR Representation | 0.118525 ms | ✅ Pass |

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

## Task 01 – Simple GEMM

| Complexity | Value |
|------------|-------|
| Time | **O(n³)** |
| Space | **O(n²)** |

---

## Task 02 – Blocking GEMM

| Complexity | Value |
|------------|-------|
| Time | **O(n³)** |
| Space | **O(n²)** |

**Observation:** Although the asymptotic complexity remains **O(n³)**, blocking significantly improves cache utilization, leading to lower practical execution time.

---

## Task 03 – CSR Graph

| Complexity | Value |
|------------|-------|
| CSR Construction | **O(V + E)** |
| Space | **O(V + E)** |

---

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
3. GeeksforGeeks – Matrix Multiplication and CSR Representation.
4. CS509 Laboratory Assignment Specification.

---