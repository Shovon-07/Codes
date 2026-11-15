#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>

using namespace std;

const int INF = INT_MAX;
const int VERTEX_COUNT = 41; // 34 Campus Locations + 7 Junctions

inline void addDirectedEdge(int u, int v, int weight, vector<vector<pair<int, int>>> &graph)
{
    graph[u].push_back({v, weight});
}

inline void addUndirectedEdge(int u, int v, int weight, vector<vector<pair<int, int>>> &graph)
{
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}

inline pair<vector<int>, int> dijkstra(int source, int destination, const vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDist != dist[u])
            continue;
        if (u == destination)
            break;

        for (auto edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[destination] == INF)
        return {{}, -1};

    vector<int> path;
    for (int v = destination; v != -1; v = parent[v])
    {
        path.push_back(v);
    }

    vector<int> exactPath;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        exactPath.push_back(path[i]);
    }

    return {exactPath, dist[destination]};
}

inline void initializeCampusGraph(vector<vector<pair<int, int>>> &graph)
{
    // 1. Bottom Outer Road
    addUndirectedEdge(0, 1, 90, graph);
    addDirectedEdge(0, 2, 140, graph);

    // 2. Left & Top Outer Perimeter
    addDirectedEdge(1, 3, 100, graph);
    addUndirectedEdge(3, 39, 50, graph);
    addUndirectedEdge(39, 4, 90, graph);
    addUndirectedEdge(4, 5, 160, graph);

    // 3. Right Outer Perimeter
    addDirectedEdge(2, 7, 110, graph);
    addUndirectedEdge(7, 6, 80, graph);
    addUndirectedEdge(6, 40, 40, graph);
    addUndirectedEdge(40, 5, 40, graph);

    // 4. Main Gate (0) & Gate 2 (1) to P3 (36)
    addDirectedEdge(0, 36, 30, graph);
    addDirectedEdge(1, 36, 90, graph);

    // 5. P3 (36) -> P4 (37) -> Bus Stand (3)
    addUndirectedEdge(36, 37, 60, graph);
    addUndirectedEdge(37, 3, 70, graph);

    // 6. P3 (36) -> P5 (38) -> Stair (33) & Parking (29)
    addUndirectedEdge(36, 38, 30, graph);
    addUndirectedEdge(38, 33, 30, graph);
    addUndirectedEdge(38, 29, 50, graph);

    // 7. Main Gate (0) & Gate 2 (1) Direct Curve to NCC Bank (23)
    addDirectedEdge(0, 23, 60, graph);
    addDirectedEdge(1, 23, 110, graph);

    // 8. NCC Bank (23) & CSE Faculty (24) Connections
    addUndirectedEdge(23, 24, 20, graph);
    addUndirectedEdge(23, 25, 30, graph);
    addUndirectedEdge(24, 25, 20, graph);
    addUndirectedEdge(24, 29, 40, graph);
    addUndirectedEdge(24, 28, 50, graph);

    // 9. CSE Faculty (24) -> P1 (34) -> P2 (35) -> EEE Lab (19) & Library (9)
    addUndirectedEdge(24, 34, 30, graph);
    addUndirectedEdge(34, 35, 40, graph);
    addUndirectedEdge(35, 19, 20, graph);
    addUndirectedEdge(35, 9, 30, graph);

    // 10. Left Courtyard Loop
    addUndirectedEdge(9, 17, 50, graph);
    addUndirectedEdge(17, 18, 30, graph);
    addUndirectedEdge(18, 19, 40, graph);
    addUndirectedEdge(17, 12, 40, graph);

    // 11. Bus Stand (3) to Top-Left Gate (10), Plaza (15), Girls Common (20)
    addUndirectedEdge(39, 10, 40, graph);
    addUndirectedEdge(3, 15, 90, graph);
    addUndirectedEdge(3, 20, 120, graph);

    // 12. Top-Left Wing
    addUndirectedEdge(10, 11, 30, graph);
    addUndirectedEdge(11, 13, 40, graph);
    addUndirectedEdge(13, 14, 20, graph);
    addUndirectedEdge(14, 15, 30, graph);
    addUndirectedEdge(13, 15, 50, graph);
    addUndirectedEdge(11, 12, 30, graph);
    addUndirectedEdge(12, 14, 40, graph);
    addUndirectedEdge(12, 16, 30, graph);
    addUndirectedEdge(16, 15, 30, graph);

    // 13. Central Spine
    addUndirectedEdge(33, 8, 30, graph);
    addUndirectedEdge(8, 15, 40, graph);

    // 14. Top-Right Wing
    addUndirectedEdge(14, 20, 50, graph);
    addUndirectedEdge(20, 21, 50, graph);
    addUndirectedEdge(15, 22, 40, graph);
    addUndirectedEdge(22, 25, 50, graph);

    // 15. East Wing Offices, Lift, Parking & Medical
    addUndirectedEdge(21, 26, 40, graph);
    addUndirectedEdge(26, 27, 20, graph);
    addUndirectedEdge(27, 28, 20, graph);
    addUndirectedEdge(29, 30, 20, graph);
    addUndirectedEdge(29, 28, 30, graph);

    // 16. Right Side Gates to Garden & Canteen
    addUndirectedEdge(21, 31, 40, graph);
    addUndirectedEdge(31, 40, 50, graph);
    addUndirectedEdge(31, 7, 60, graph);
    addUndirectedEdge(28, 32, 30, graph);
    addUndirectedEdge(32, 7, 40, graph);
}

#endif