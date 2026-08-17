#ifndef CSR_H
#define CSR_H

#include <vector> // vector library
#include <string> // string library
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