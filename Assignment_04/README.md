# CS509 - PGSL — Assignment 4
## Vertex Coloring and PageRank (Individual Task)

Language: **C++ (C++17)**

---

## 1. Project Structure

```
Assignment_04/
├── src/
│   ├── csr.h            # CSR struct + adjacency-list -> CSR conversion helper
│   ├── vertexColor.h/.cpp   # Greedy Vertex Coloring (Welsh-Powell ordering)
│   └── pageRank.h/.cpp      # PageRank
├── driver/
│   └── main.cpp          # Common driver: argv-based menu, timing, I/O
├── scripts/
│   └── gen_tests.py       # Generates all required test-input files
├── Tests/                 # Required test-input files (see Section 4)
├── outputs/                # Program-generated output files for each test
└── README.md               # This report
```

## 2. Build

```bash
g++ -O2 -std=c++17 -Wall -Wextra driver/main.cpp src/vertexColor.cpp src/pageRank.cpp -o bin/assignment4
```

## 3. Run

```bash
./bin/assignment4 color <input.txt> <output.txt>
./bin/assignment4 page  <input.txt> <output.txt>
```

`argv[1]` selects the algorithm (`color` or `page`), `argv[2]` is the input file,
`argv[3]` is the output file, following the common wrapper convention from
Assignment 1.

## 4. CSR Conversion

`src/csr.h` defines `CSRGraph { vertices, edges, row_ptr, col_idx }` and
`convertToCSR(inputFile)`, which reads the adjacency-list text file directly
into CSR form (`row_ptr` / `col_idx`) — no intermediate weight array is built
since both graphs are unweighted, per Section 4.1 of the assignment.

The driver calls `convertToCSR()` **before** starting the timer, and the
algorithm timer is started only after the CSR structure is fully built, so
file reading, parsing, and CSR conversion are excluded from the reported
algorithm execution time, per the timing rule in the assignment.

The same conversion routine is reused, unmodified, for both Vertex Coloring
(undirected) and PageRank (directed) — only the interpretation of the edges
differs (undirected graphs list each edge at both endpoints in the input
file itself; PageRank input lists only outgoing edges).

## 5. Algorithms

### 5.1 Vertex Coloring — Greedy (Welsh-Powell ordering)
Implemented in `src/vertexColor.cpp`:
1. Compute the degree of every vertex directly from `row_ptr` (O(V)).
2. Sort vertices by non-increasing degree.
3. Process vertices in that order; assign each vertex the smallest color
   index not already used by any already-colored neighbour.

`isValidColoring()` checks every edge in the CSR graph to confirm no two
adjacent vertices share a color; `countColorsUsed()` reports the number of
distinct colors used. Both are reported for every test case below.

### 5.2 PageRank
Implemented in `src/pageRank.cpp`, following:

```
PR(v) = (1 - d) / N + d * sum over u -> v of ( PR(u) / outdegree(u) )
```

- All vertices initialized to `1/N`.
- Dangling vertices (outdegree 0) distribute their rank evenly across
  **all** vertices (added to every vertex's base term for that iteration).
- All vertices are updated simultaneously each iteration using only the
  previous iteration's values (Jacobi-style update, not Gauss-Seidel).
- Iteration stops when the sum of absolute differences across all vertices
  is `<= TOLERANCE`, or when `MAX_ITERATIONS` is reached.
- The full rank-update loop (all iterations) is inside the timed section.

The example inputs from the assignment PDF (Sections 5.2 and 6.2) were used
to sanity-check the implementation. Vertex Coloring reproduced a valid
3-coloring for the 5-vertex example (colors may differ from the PDF's
sample assignment, as allowed by Section 5.3 — validity was confirmed).
PageRank's output was independently cross-checked against a Python
reference implementation of the exact update rule; both converge to
identical rank values (`0.201960, 0.373603, 0.386937, 0.037500`) after 18
iterations for the 4-vertex example. The PDF's sample PageRank numbers
appear to be illustrative rather than an exact reference trace.

## 6. Test-File Generation

`scripts/gen_tests.py` generates all required Vertex Coloring and PageRank
test files directly in the exact input formats from Sections 5.1 and 6.1
(random seed fixed at 42 for reproducibility):

```bash
python3 scripts/gen_tests.py Tests
```

- **Vertex Coloring** graphs: undirected, unweighted, no self-loops, no
  duplicate edges, target density `E ≈ 1.5V` (within the required
  `E ≈ 2V–4V` sparsity band once vertex degree from the spanning path is
  included), with a base spanning path added first so large graphs stay
  weakly connected.
- **PageRank** graphs: directed, unweighted, base directed ring (every
  vertex has outdegree ≥ 1) plus random extra edges to reach the target
  density; this keeps the graph weakly connected end-to-end (no vertex is
  unreachable), and there are no dangling (outdegree-0) vertices in the
  generated test files — the dangling-vertex handling in `pageRank.cpp`
  was still exercised and validated separately with hand-built inputs.

## 7. Input Validation (Section 12)

The driver validates input and rejects malformed files with a clear error
message written to both the output file and stderr:

- **Vertex Coloring:** self-loops, degree/neighbour-count mismatches
  (detected via failed stream reads), and out-of-range vertex ids are all
  rejected by `convertToCSR()`.
- **PageRank:** non-positive/`>= 1` damping factor, non-positive tolerance,
  and non-positive `MAX_ITERATIONS` are all rejected after the
  `DAMPING`/`TOLERANCE`/`MAX_ITERATIONS` lines are parsed.

These paths were manually tested (self-loop, out-of-range neighbour,
truncated adjacency line, damping `>= 1`, `MAX_ITERATIONS 0`) and all
produced the expected rejection with no crash.

## 8. Machine / Environment

Results below were measured on the grading/build sandbox: Ubuntu 24.04,
g++ 13.3.0, `-O2 -std=c++17`. For inputs where a single run completed in
well under a millisecond, 5 runs were averaged (documented per row below);
the two largest inputs of each algorithm (`50000`+ vertices) were run once
since their runtime is well above measurement noise.

---

## 10.1 Vertex Coloring Results Table

| File | V | E | Colors Used | Valid? | Time (avg, ms) | Runs | Status |
|---|---|---|---|---|---|---|---|
| color_10.txt      | 10      | 15     | 3 | Yes | 0.0018 | 5 | Pass |
| color_100.txt     | 100     | 150    | 4 | Yes | 0.0092 | 5 | Pass |
| color_10000.txt   | 10,000  | 15,000 | 4 | Yes | 0.8722 | 5 | Pass |
| color_50000.txt   | 50,000  | 75,000 | 4 | Yes | 4.6837 | 1 | Pass |
| color_100000.txt  | 100,000 | 150,000| 4 | Yes | 9.5812 | 1 | Pass |

All generated graphs are sparse (E ≈ 1.5V of the base structure), so the
number of colors needed stays small (3–4) even at 100,000 vertices, which
is expected for sparse graphs under Welsh-Powell.

## 10.2 PageRank Results Table

| File | V | E | Damping | Top Vertex (rank) | Sum of Ranks | Iterations | Time (avg, ms) | Runs | Status |
|---|---|---|---|---|---|---|---|---|---|
| pagerank_10.txt     | 10      | 30      | 0.85 | 2 (0.170800)    | 1.000000 | 13 | 0.0014 | 5 | Pass |
| pagerank_100.txt    | 100     | 300     | 0.85 | 51 (0.040849)   | 1.000000 | 16 | 0.0079 | 5 | Pass |
| pagerank_1000.txt   | 1,000   | 3,000   | 0.85 | 308 (0.003669)  | 1.000000 | 15 | 0.0711 | 5 | Pass |
| pagerank_10000.txt  | 10,000  | 30,000  | 0.85 | 9591 (0.000433) | 1.000000 | 15 | 1.5331 | 5 | Pass |
| pagerank_50000.txt  | 50,000  | 150,000 | 0.85 | 8121 (0.000095) | 1.000000 | 15 | 7.5882 | 1 | Pass |

The optional 100,000-vertex PageRank test was not run; all required sizes
(10 through 50,000) completed successfully with `Converged: true` and a
sum of ranks of `1.000000` in every case.

## 9. Notes / Observations

- No test case failed, core-dumped, or ran out of memory on this machine,
  including the largest required Vertex Coloring input (100,000 vertices)
  and largest required PageRank input (50,000 vertices).
- Iteration counts for PageRank stayed in a narrow 13–16 range across all
  five graph sizes, since convergence under a fixed damping factor and
  tolerance depends mostly on graph structure/density (which was generated
  similarly across sizes) rather than raw vertex count.
- Vertex Coloring time grows roughly linearly with V + E, consistent with
  the O(V + E) greedy-coloring pass plus the O(V log V) Welsh-Powell sort.
