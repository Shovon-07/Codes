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

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>
// using namespace std;
// int INF = INT_MAX;

// void addVertext(int v1, int v2, int weight, vector<vector<pair<int, int>>> &graph)
// {
//     graph[v1].push_back({v2, weight});
//     // graph[v2].push_back({v1, weight});
// }

// void dijkstra(int source, int destination, vector<vector<pair<int, int>>> &graph)
// {
//     int n = graph.size();
//     // dist প্রতিটি Node-এ Source থেকে পৌঁছানোর সবচেয়ে কম Distance সংরক্ষণ করবে।
//     vector<int> dist(n, INF);
//     // parent Vector দিয়ে আমরা Shortest Path-টি পুনরুদ্ধার করব।
//     vector<int> parent(n, -1);

//     priority_queue<
//         pair<int, int>,
//         vector<pair<int, int>>,
//         greater<pair<int, int>>>
//         minPQ;

//     dist[source] = 0;        // Source থেকে Source-এর Distance 0।
//     minPQ.push({0, source}); // Source Node-কে Priority Queue-তে যুক্ত করা হলো। {0, A}

//     while (!minPQ.empty())
//     {
//         int currentDist = minPQ.top().first; // সেই Entry-এর Distance
//         int u = minPQ.top().second;          // Node নম্বর
//         minPQ.pop();

//         // পুরোনো entry হলে skip
//         if (currentDist != dist[u])
//             continue;

//         // Destination-এ পৌঁছে গেছি
//         if (u == destination)
//             break;
//     }

//     cout << minPQ.top().first << endl;
// }

// int main()
// {
//     int vertex = 4;
//     vector<vector<pair<int, int>>> graph(vertex);

//     // Vertex connection
//     addVertext(0, 1, 4, graph);
//     addVertext(0, 2, 2, graph);

//     addVertext(1, 0, 4, graph);
//     addVertext(1, 2, 1, graph);
//     addVertext(1, 3, 5, graph);

//     addVertext(2, 0, 2, graph);
//     addVertext(2, 1, 1, graph);
//     addVertext(2, 3, 8, graph);

//     addVertext(3, 1, 5, graph);
//     addVertext(3, 2, 8, graph);

//     dijkstra(1, 3, graph);

//     // Traverse adjacency list
//     for (int i = 0; i < vertex; i++)
//     {
//         for (int j = 0; j < graph[i].size(); j++)
//         {
//             int con = graph[i][j].first, weight = graph[i][j].second;
//             cout << i << " -> " << con << " = " << weight << " km" << endl;
//         }
//     }

//     return 0;
// }

// /*
// n = number of node
// dist প্রতিটি Node-এ Source থেকে পৌঁছানোর সবচেয়ে কম Distance সংরক্ষণ করবে।
// parent Vector দিয়ে আমরা Shortest Path-টি পুনরুদ্ধার করব।
// */