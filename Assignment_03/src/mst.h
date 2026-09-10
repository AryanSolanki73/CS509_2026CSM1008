#ifndef MST_H
#define MST_H
#include "../../Assignment_02/src/csr.h"

// MST edges struct to store 2 edges and weights between them
struct MSTEdge {
    int u;
    int v;
    long long weight;
};

#endif