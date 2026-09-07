#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include <vector>
#include <string>
using namespace std;

// To read the Input Matrix
vector<vector<long long>> readMatrix(const string& filename);

// Main Algorithm floydWarshall function in floydWarshall.cpp file
vector<vector<long long>> floydWarshall(vector<vector<long long>> matrix);

#endif