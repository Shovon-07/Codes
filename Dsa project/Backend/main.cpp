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
int vertex = 38; // 34 Campus Locations + 4 Road Junctions
vector<vector<pair<int, int>>> graph(vertex);

void addDirectedEdge(int u, int v, int weight, vector<vector<pair<int, int>>> &graph);
void addUndirectedEdge(int u, int v, int weight, vector<vector<pair<int, int>>> &graph);
pair<vector<int>, int> dijkstra(int source, int destination, vector<vector<pair<int, int>>> &graph);

int main()
{
    httplib::Server server;

    server.set_default_headers({{"Access-Control-Allow-Origin", "*"},
                                {"Access-Control-Allow-Methods", "GET, POST, OPTIONS"},
                                {"Access-Control-Allow-Headers", "Content-Type"}});

    // 1. Bottom Outer Road
    addUndirectedEdge(0, 1, 90, graph); // Main Gate <-> Gate 2
    addDirectedEdge(0, 2, 140, graph);  // Main Gate -> Gate 3

    // 2. Outer Perimeter
    addDirectedEdge(1, 3, 100, graph);   // Gate 2 -> Bus Stand
    addUndirectedEdge(3, 35, 45, graph); // Bus Stand <-> Top-Left Curve
    addUndirectedEdge(35, 4, 85, graph); // Top-Left Curve <-> Play Ground 1
    addUndirectedEdge(4, 5, 160, graph); // Play Ground 1 <-> Play Ground 2

    addDirectedEdge(2, 7, 110, graph);   // Gate 3 -> Canteen
    addUndirectedEdge(7, 6, 80, graph);  // Canteen <-> Garden
    addUndirectedEdge(6, 36, 35, graph); // Garden <-> Top-Right Junction
    addUndirectedEdge(36, 5, 40, graph); // Top-Right Junction <-> Play Ground 2

    // 3. Main Gate & Gate 2 Entry Curves (Routes 1-80)
    addDirectedEdge(0, 34, 35, graph); // Main Gate -> Main Entry T-Junction
    addDirectedEdge(1, 34, 95, graph); // Gate 2 -> Main Entry T-Junction
    addDirectedEdge(0, 3, 120, graph); // Main Gate -> Bus Stand (Route 31)

    addDirectedEdge(34, 33, 45, graph); // Main Entry T-Junction -> Stair (Routes 43-47)
    addDirectedEdge(34, 37, 40, graph); // Main Entry T-Junction -> South Junction

    // 4. South Corridor (CSE Faculty, NCC Bank, Parking, Library, EEE Lab)
    addUndirectedEdge(37, 24, 45, graph); // South Junction <-> CSE Faculty (Routes 1-20)
    addUndirectedEdge(37, 29, 50, graph); // South Junction <-> Parking (Routes 21-22, 48-61)

    addUndirectedEdge(24, 23, 25, graph); // CSE Faculty <-> NCC Bank (Route 1)
    addUndirectedEdge(24, 25, 25, graph); // CSE Faculty <-> BBA Dept
    addUndirectedEdge(24, 29, 40, graph); // CSE Faculty <-> Parking (Routes 3-4)
    addUndirectedEdge(24, 28, 45, graph); // CSE Faculty <-> CSE Prog. Office (Routes 5-6, 18-20)
    addUndirectedEdge(24, 27, 40, graph); // CSE Faculty <-> Lift (Route 62)

    addUndirectedEdge(24, 19, 45, graph); // CSE Faculty <-> EEE Lab (Route 7)
    addUndirectedEdge(24, 9, 80, graph);  // CSE Faculty <-> Library (Routes 8-17)

    // 5. Left Courtyard Loop
    addUndirectedEdge(9, 17, 50, graph);  // Library <-> Inventory Room
    addUndirectedEdge(17, 18, 30, graph); // Inventory Room <-> Auditorium
    addUndirectedEdge(18, 19, 35, graph); // Auditorium <-> EEE Lab
    addUndirectedEdge(9, 19, 45, graph);  // Library <-> EEE Lab (Routes 61, 105)
    addUndirectedEdge(17, 12, 45, graph); // Inventory Room <-> Boys Common Room (Routes 11, 58, 76, 89, 101)

    // 6. Bus Stand Direct Connections
    addUndirectedEdge(35, 10, 40, graph); // Top-Left Curve <-> Top-Left Gate
    addUndirectedEdge(3, 15, 95, graph);  // Bus Stand <-> Plaza (Routes 28-30, 36-42)
    addUndirectedEdge(3, 20, 115, graph); // Bus Stand <-> Girls Common Room (Routes 69-79, 86-92)

    // 7. Top-Left Academic Wing
    addUndirectedEdge(10, 11, 30, graph); // Gate <-> Info Desk
    addUndirectedEdge(11, 13, 35, graph); // Info Desk <-> Mosque
    addUndirectedEdge(13, 14, 25, graph); // Mosque <-> Pharmacy Dept
    addUndirectedEdge(14, 15, 30, graph); // Pharmacy Dept <-> Plaza
    addUndirectedEdge(13, 15, 50, graph); // Mosque <-> Plaza (Routes 29, 37, 46)

    addUndirectedEdge(11, 12, 30, graph); // Info Desk <-> Boys Common Room
    addUndirectedEdge(12, 14, 40, graph); // Boys Common Room <-> Pharmacy Dept (Routes 12, 57, 75, 88, 100)
    addUndirectedEdge(12, 16, 25, graph); // Boys Common Room <-> Sinat
    addUndirectedEdge(16, 15, 30, graph); // Sinat <-> Plaza (Routes 30, 38, 47)

    // 8. Central Spine & Stair
    addUndirectedEdge(33, 8, 25, graph); // Stair <-> Central Corridor
    addUndirectedEdge(8, 15, 40, graph); // Central Corridor <-> Plaza (Routes 43-47)

    // 9. Top-Right Wing
    addUndirectedEdge(14, 20, 45, graph); // Pharmacy Dept <-> Girls Common Room (Routes 13, 56, 74, 87, 99)
    addUndirectedEdge(20, 21, 45, graph); // Girls Common Room <-> CR Center
    addUndirectedEdge(15, 22, 35, graph); // Plaza <-> American Corner (Routes 39-42, 44-45)
    addUndirectedEdge(22, 25, 45, graph); // American Corner <-> BBA Dept (Routes 40, 42, 45)
    addUndirectedEdge(23, 25, 35, graph); // NCC Bank <-> BBA Dept

    // 10. East Wing Offices, Lift, Parking & Medical
    addUndirectedEdge(21, 26, 35, graph); // CR Center <-> EEE Prog. Office
    addUndirectedEdge(26, 27, 20, graph); // EEE Prog. Office <-> Lift
    addUndirectedEdge(27, 28, 20, graph); // Lift <-> CSE Prog. Office

    addUndirectedEdge(29, 30, 15, graph); // Parking <-> Medical (Routes 4, 22)
    addUndirectedEdge(29, 28, 30, graph); // Parking <-> CSE Prog. Office (Route 48)
    addUndirectedEdge(29, 27, 40, graph); // Parking <-> Lift (Routes 49-61)

    // 11. Right Side Gates to Garden & Canteen
    addUndirectedEdge(21, 31, 35, graph); // CR Center <-> Top-Right Gate
    addUndirectedEdge(31, 36, 45, graph); // Top-Right Gate <-> Top-Right Junction (Routes 15-16, 52-53, 71-72)
    addUndirectedEdge(31, 7, 55, graph);  // Top-Right Gate <-> Canteen (Routes 17, 54, 73)

    addUndirectedEdge(28, 32, 25, graph); // CSE Prog. Office <-> Bottom-Right Gate
    addUndirectedEdge(32, 7, 40, graph);  // Bottom-Right Gate <-> Canteen (Routes 6, 93-105)

    server.Options("/find-path", [](const httplib::Request &req, httplib::Response &res)
                   { res.status = 204; });

    server.Post("/find-path", [](const httplib::Request &req, httplib::Response &res)
                {
        try
        {
            json data = json::parse(req.body);
            int source = data.at("source").get<int>();
            int destination = data.at("destination").get<int>();

            auto [path, totalDist] = dijkstra(source, destination, graph);

            json response = {
                {"path", path},
                {"distance", totalDist},
                {"reachable", !path.empty()}
            };

            res.set_content(response.dump(), "application/json");
        }
        catch (const exception &e)
        {
            res.status = 400;
            res.set_content(R"({"error":"Invalid input"})", "application/json");
        } });

    server.Get("/locations", [](const httplib::Request &req, httplib::Response &res)
               {
        json locations = {
            {"locations", {
                {{"id", 0}, {"name", "Main Gate"}},
                {{"id", 1}, {"name", "Gate 2"}},
                {{"id", 2}, {"name", "Gate 3"}},
                {{"id", 3}, {"name", "Bus Stand"}},
                {{"id", 4}, {"name", "Play Ground 1"}},
                {{"id", 5}, {"name", "Play Ground 2"}},
                {{"id", 6}, {"name", "Garden"}},
                {{"id", 7}, {"name", "Canteen"}},
                {{"id", 8}, {"name", "Central Corridor"}},
                {{"id", 9}, {"name", "Library (b)"}},
                {{"id", 10}, {"name", "Gate (Top-Left)"}},
                {{"id", 11}, {"name", "Info Desk"}},
                {{"id", 12}, {"name", "Boys Common Room (b)"}},
                {{"id", 13}, {"name", "Mosque (2nd)"}},
                {{"id", 14}, {"name", "Pharmacy Dept (b)"}},
                {{"id", 15}, {"name", "Plaza (2nd)"}},
                {{"id", 16}, {"name", "Sinat (3rd)"}},
                {{"id", 17}, {"name", "Inventory Room (b)"}},
                {{"id", 18}, {"name", "Auditorium (b)"}},
                {{"id", 19}, {"name", "EEE Lab (b)"}},
                {{"id", 20}, {"name", "Girls Common Room"}},
                {{"id", 21}, {"name", "CR Center"}},
                {{"id", 22}, {"name", "American Corner (2nd)"}},
                {{"id", 23}, {"name", "NCC Bank"}},
                {{"id", 24}, {"name", "CSE Faculty"}},
                {{"id", 25}, {"name", "BBA Dept (2nd)"}},
                {{"id", 26}, {"name", "EEE Prog. Office"}},
                {{"id", 27}, {"name", "Lift"}},
                {{"id", 28}, {"name", "CSE Prog. Office"}},
                {{"id", 29}, {"name", "Parking"}},
                {{"id", 30}, {"name", "Medical"}},
                {{"id", 31}, {"name", "Gate (Top-Right)"}},
                {{"id", 32}, {"name", "Gate (Bottom-Right)"}},
                {{"id", 33}, {"name", "Stair"}}
            }}
        };

        res.set_content(locations.dump(), "application/json"); });

    const char *envPort = getenv("PORT");
    int port = envPort ? stoi(envPort) : 8080;
    cout << "C++ Backend running on port " << port << '\n';
    server.listen("0.0.0.0", port);
}

void addDirectedEdge(int u, int v, int weight, vector<vector<pair<int, int>>> &graph)
{
    graph[u].push_back({v, weight});
}

void addUndirectedEdge(int u, int v, int weight, vector<vector<pair<int, int>>> &graph)
{
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}

pair<vector<int>, int> dijkstra(int source, int destination, vector<vector<pair<int, int>>> &graph)
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
    {
        return {{}, -1};
    }

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