# CS509 Laboratory Assignments 

This repository contains the **laboratory assignments** for the **CS509** course as part of the **M.Tech in Computer Science and Engineering** programme at the **Indian Institute of Technology (IIT) Ropar**.

The repository serves as a centralized collection of all collaborative programming assignments completed during the course. Each assignment is organized into independent tasks with their respective source code, driver programs, test cases, outputs, and build configurations.

---

# Repository Structure

```
CS509_2026CSM1008
│
├── Assignment_01
│   ├── Task_01
│   ├── Task_02
│   ├── Task_03
│ 
├── Assignment_02
│   ├── Task_01
│   ├── Task_02
│   ├── ...
│
├── Assignment_03
│   ├── ...
│
├── common_wrapper/wrapper.cpp
│
└── README.md
```

As the course progresses, new assignment directories will be added while maintaining a consistent project structure.

---

# Assignment Organization

Each assignment is divided into one or more independent tasks.

A typical task follows the structure:

```
Task_xx/
│
├── driver/        # Driver program
├── src/           # Source and header files
├── Testcases/     # Input test cases
├── outputs/       # Generated outputs
```

This modular organization keeps each implementation self-contained and easy to build, test, and evaluate.

---

# Build Instructions

Navigate to the desired task directory.

Example:

```bash
cd CS509_2026CSM1008/Assignment_01/common_wrapper
```

For assignments I have provided a common wrapper, compile it using:

```bash
g++ wrapper.cpp -o wrapper_app
```

and execute in following directory

```bash
cd CS509_2026CSM1008/Assignment_01
```

Using the below command

```bash
common_wrapper/wrapper
```

---

# Technologies Used

- **Programming Language:** C++
- **Compiler:** GCC (g++)
- **Build System:** GNU Make
- **Platform:** Linux

---

# Repository Objectives

The assignment_01 in this repository cover various topics in computer science and high-performance computing, including but not limited to:

- General Matrix Multiplication (GEMM) - Simple Implementation 
- General Matrix Multiplication (GEMM) - Blocking Implementation 
- Compressed Sparse Row(CSR)

---

# Academic Information

**Course:** CS509

**Programme:** M.Tech in Computer Science and Engineering

**Institute:** Indian Institute of Technology (IIT) Ropar

---

## Authors

- **Aryan Solanki** — 2026CSM1008

---

## License

This repository is maintained for academic and educational purposes. Unauthorized copying or submission of the solutions as one's own coursework is discouraged.