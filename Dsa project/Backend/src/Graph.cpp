#include "Graph.h"

void addVertex(int v1, int v2, int weight, Graph &graph)
{
    // Undirected graph
    graph[v1].push_back({v2, weight});
    graph[v2].push_back({v1, weight});
}
