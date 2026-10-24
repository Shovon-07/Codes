#include <iostream>
#include <httplib.h>
#include <nlohmann/json.hpp>
#include <cstdlib>

#include <vector>
#include <queue>
#include <climits>

using namespace std;
using json = nlohmann::json;

int INF = INT_MAX;
int vertex = 10;
vector<vector<pair<int, int>>> graph(vertex);

void addVertext(int v1, int v2, int weight, vector<vector<pair<int, int>>> &graph);

vector<int> dijkstra(int source, int destination, vector<vector<pair<int, int>>> &graph);

int main()
{
    httplib::Server server;
    // CORS headers
    server.set_default_headers({{"Access-Control-Allow-Origin", "https://vu-navigation.netlify.app"}, {"Access-Control-Allow-Methods", "GET, POST, OPTIONS"}, {"Access-Control-Allow-Headers", "Content-Type"}});

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

    // OPTIONS: Preflight request
    server.Options("/find-path", [](const httplib::Request &req, httplib::Response &res)
                   { res.status = 204; });

    // POST: Find path
    server.Post("/find-path", [](const httplib::Request &req, httplib::Response &res)
                {
                    try
                    {
                        json data = json::parse(req.body);
                        int source = data.at("source").get<int>();
                        int destination = data.at("destination").get<int>();
                        vector<int> result = dijkstra(source, destination, graph);

                        json response = {
                            {"path", result}};

                        res.set_content(
                            response.dump(),
                            "application/json");
                    }
                    catch (const exception &e)
                    {
                        res.status = 400;
                        res.set_content(
                            R"({"error":"Invalid input"})",
                            "application/json");
                    } });

    server.Get("/locations", [](const httplib::Request &req, httplib::Response &res)
               { json locations = {
        {"locations", {
            {{"id", 0}, {"name", "Main gate"}},
            {{"id", 1}, {"name", "Gate 2"}},
            {{"id", 2}, {"name", "Gate 3"}},
            {{"id", 3}, {"name", "Bus stand"}},
            {{"id", 4}, {"name", "Ground 1"}},
            {{"id", 5}, {"name", "Ground 2"}},
            {{"id", 6}, {"name", "Botanical garden"}},
            {{"id", 7}, {"name", "Cafeteria"}},
            {{"id", 8}, {"name", "Parking"}},
            {{"id", 9}, {"name", "Flower garden"}},
        }}
    };

    res.set_content(
        locations.dump(),
        "application/json"
    ); });

    const char *envPort = getenv("PORT");
    int port = envPort ? stoi(envPort) : 8080;
    cout << "C++ Backend running on port " << port << '\n';
    server.listen("0.0.0.0", port);
}

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

    // Make shortest path
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
