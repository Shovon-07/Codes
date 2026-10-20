#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void dijkstra(int source, int destination,
              vector<vector<pair<int, int>>> &graph)
{

    int n = graph.size();

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    // Min-heap: {distance, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {

        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // পুরোনো entry হলে skip
        if (currentDist != dist[u])
            continue;

        // Destination-এ পৌঁছে গেছি
        if (u == destination)
            break;

        // u-এর সব neighbor পরীক্ষা
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
    {
        cout << "No path found\n";
        return;
    }

    // Shortest path তৈরি
    vector<int> path;

    for (int v = destination; v != -1;
         v = parent[v])
    {
        path.push_back(v);
    }

    // উল্টো দিক থেকে সঠিক দিক
    cout << "Shortest Path: ";

    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];

        if (i > 0)
            cout << " -> ";
    }

    cout << "\nTotal Distance: "
         << dist[destination] << " km\n";
}

int main()
{

    int n = 4;

    vector<vector<pair<int, int>>> graph(n);

    // A = 0, B = 1, C = 2, D = 3

    auto addRoad = [&](int u, int v, int w)
    {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    };

    addRoad(0, 1, 4); // A-B
    addRoad(0, 2, 2); // A-C
    addRoad(1, 3, 5); // B-D
    addRoad(2, 3, 8); // C-D
    addRoad(1, 2, 1); // B-C

    dijkstra(0, 3, graph);

    return 0;
}