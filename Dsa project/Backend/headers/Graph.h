#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <utility>
using namespace std;
using Graph = vector<vector<pair<int, int>>>;
void addVertex(int v1, int v2, int weight, Graph &graph);
#endif
