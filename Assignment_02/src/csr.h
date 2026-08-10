#ifndef CSR_H
#define CSR_H

#include <vector>
#include <string>

using namespace std;

struct CSRGraph {

    int vertices;
    int edges;

    vector<int> row_ptr;
    vector<int> col;
    vector<long long> weight;
};

CSRGraph convertToCSR(const string& filename);

#endif