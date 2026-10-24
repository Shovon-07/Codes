#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int INF = INT_MAX;

void addVertext(int v1, int v2, int weight, vector<vector<pair<int, int>>> &graph)
{
    graph[v1].push_back({v2, weight});
    graph[v2].push_back({v1, weight});
}

vector<int> dijkstra(int source, int destination,
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
        return {};
    }

    // Shortest path তৈরি
    vector<int> path;

    for (int v = destination; v != -1;
         v = parent[v])
    {
        path.push_back(v);
    }

    // উল্টো দিক থেকে সঠিক দিক
    vector<int> exactPath;
    cout << "Shortest Path: ";

    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        exactPath.push_back(path[i]);

        if (i > 0)
            cout << " -> ";
    }

    cout << "\nTotal Distance: " << dist[destination] << " m\n";

    return exactPath;
}

int main()
{
    int vertex = 10;
    vector<vector<pair<int, int>>> graph(vertex);

    // Vertex connection
    addVertext(0, 1, 50, graph);
    addVertext(0, 2, 50, graph);
    addVertext(0, 3, 150, graph);
    addVertext(0, 8, 130, graph);
    addVertext(1, 3, 10, graph);
    addVertext(3, 4, 20, graph);
    addVertext(2, 3, 300, graph);
    addVertext(4, 9, 30, graph);
    addVertext(9, 5, 100, graph);
    addVertext(5, 6, 50, graph);
    addVertext(6, 7, 10, graph);
    addVertext(7, 2, 150, graph);

    vector<int> result = dijkstra(2, 3, graph);

    cout << "\n\n\n Print :" << result[0];

    // Traverse adjacency list
    // for (int i = 0; i < vertex; i++)
    // {
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         int con = graph[i][j].first, weight = graph[i][j].second;
    //         cout << i << " -> " << con << " = " << weight << " km" << endl;
    //     }
    // }

    return 0;
}

// /*
// n = number of node
// dist প্রতিটি Node-এ Source থেকে পৌঁছানোর সবচেয়ে কম Distance সংরক্ষণ করবে।
// parent Vector দিয়ে আমরা Shortest Path-টি পুনরুদ্ধার করব।
// */
