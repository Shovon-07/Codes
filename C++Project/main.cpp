#include <iostream>
#include <vector>
using namespace std;

void addVertext(int v1, int v2, int weight, vector<vector<pair<int, int>>> &graph)
{
    graph[v1].push_back({v2, weight});
    // graph[v2].push_back({v1, weight});
}

void dijkstra(int source, int destination, vector<vector<pair<int, int>>> &graph) {}

int main()
{
    int vertex = 4;
    vector<vector<pair<int, int>>> graph(vertex);

    // Vertex connection
    addVertext(0, 1, 4, graph);
    addVertext(0, 2, 2, graph);

    addVertext(1, 0, 4, graph);
    addVertext(1, 2, 1, graph);
    addVertext(1, 3, 5, graph);

    addVertext(2, 0, 2, graph);
    addVertext(2, 1, 1, graph);
    addVertext(2, 3, 8, graph);

    addVertext(3, 1, 5, graph);
    addVertext(3, 2, 8, graph);

    dijkstra(1, 3, graph);

    // Traverse adjacency list
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int con = graph[i][j].first, weight = graph[i][j].second;
            cout << i << " -> " << con << " = " << weight << " km" << endl;
        }
    }

    return 0;
}