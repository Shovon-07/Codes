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
int vertex = 39; // 33 Main Locations + 6 Road Junctions for exact curve routing
vector<vector<pair<int, int>>> graph(vertex);

// Directed edge based on arrows in the hand-drawn map
void addDirectedEdge(int u, int v, int weight, vector<vector<pair<int, int>>> &graph);
pair<vector<int>, int> dijkstra(int source, int destination, vector<vector<pair<int, int>>> &graph);

int main()
{
    httplib::Server server;

    server.set_default_headers({{"Access-Control-Allow-Origin", "*"},
                                {"Access-Control-Allow-Methods", "GET, POST, OPTIONS"},
                                {"Access-Control-Allow-Headers", "Content-Type"}});

    /*
     * Node Mapping:
     * 0: Main Gate, 1: Gate 2, 2: Gate 3, 3: Bus Stand, 4: Play Ground 1,
     * 5: Play Ground 2, 6: Garden, 7: Canteen (Containe), 8: Central Corridor (Mid Gate),
     * 9: Library (b), 10: Gate (Top-Left), 11: Info Desk, 12: Boys Common Room (b),
     * 13: Mosque (2nd), 14: Pharmacy Dept (b), 15: Plaza (2nd), 16: Sinat (3rd),
     * 17: Inventory Room (b), 18: Auditorium (b), 19: EEE Lab (b), 20: Girls Common Room,
     * 21: CR Center, 22: American Corner (2nd), 23: NCC Bank, 24: CSE Faculty,
     * 25: BBA Dept (2nd), 26: EEE Prog. Office, 27: Lift, 28: CSE Prog. Office,
     * 29: Parking, 30: Medical, 31: Gate (Top-Right), 32: Gate (Bottom-Right)
     *
     * Junction Nodes (for exact arrow intersections):
     * 33: Main Entry T-Junction (above Main Gate)
     * 34: Top-Left Outer Curve Junction (above Bus Stand)
     * 35: Top-Right Outer Junction (between Play Ground 2 & Garden)
     * 36: Central Spine Junction (below Plaza)
     * 37: South-East Corridor Junction (below CSE Faculty)
     * 38: East Corridor Junction (below Lift)
     */

    // --- 1. Bottom Horizontal Road (Arrows point outwards from Main Gate) ---
    addDirectedEdge(0, 1, 90, graph);  // Main Gate -> Gate 2 (90m)
    addDirectedEdge(0, 2, 140, graph); // Main Gate -> Gate 3 (140m)

    // --- 2. Left & Top Outer Perimeter (Arrows go Up & Right) ---
    addDirectedEdge(1, 3, 100, graph); // Gate 2 -> Bus Stand (100m)
    addDirectedEdge(3, 34, 45, graph); // Bus Stand -> Top-Left Curve (45m)
    addDirectedEdge(34, 4, 85, graph); // Top-Left Curve -> Play Ground 1 (85m)
    addDirectedEdge(4, 5, 160, graph); // Play Ground 1 -> Play Ground 2 (160m)

    // --- 3. Right Outer Perimeter (Arrows go Up from Gate 3 to Canteen -> Garden -> PG 2) ---
    addDirectedEdge(2, 7, 110, graph); // Gate 3 -> Canteen (110m)
    addDirectedEdge(7, 6, 80, graph);  // Canteen -> Garden (80m)
    addDirectedEdge(6, 35, 35, graph); // Garden -> Top-Right Junction (35m)
    addDirectedEdge(35, 5, 40, graph); // Top-Right Junction -> Play Ground 2 (40m)

    // --- 4. Main Gate Entry & Inner-Left Outer Loops ---
    addDirectedEdge(0, 33, 35, graph); // Main Gate -> Main Entry T-Junction (35m)
    addDirectedEdge(1, 33, 95, graph); // Gate 2 -> Main Entry T-Junction (95m)
    addDirectedEdge(33, 9, 45, graph); // Main Entry T-Junction -> Library (b) (45m)
    addDirectedEdge(33, 8, 55, graph); // Main Entry T-Junction -> Central Corridor (55m)

    // --- 5. Bus Stand Connections ---
    addDirectedEdge(9, 3, 90, graph);   // Library (b) -> Bus Stand (90m)
    addDirectedEdge(34, 10, 40, graph); // Top-Left Curve -> Top-Left Gate (40m)

    // --- 6. Top-Left Academic Building Wing ---
    addDirectedEdge(10, 11, 30, graph); // Top-Left Gate -> Info Desk (30m)
    addDirectedEdge(11, 13, 35, graph); // Info Desk -> Mosque (2nd) (35m)
    addDirectedEdge(13, 14, 25, graph); // Mosque (2nd) -> Pharmacy Dept (b) (25m)
    addDirectedEdge(14, 15, 30, graph); // Pharmacy Dept (b) -> Plaza (2nd) (30m)

    addDirectedEdge(11, 12, 30, graph); // Info Desk -> Boys Common Room (b) (30m)
    addDirectedEdge(12, 16, 25, graph); // Boys Common Room (b) -> Sinat (3rd) (25m)
    addDirectedEdge(16, 36, 25, graph); // Sinat (3rd) -> Central Spine Junction (25m)

    // --- 7. Central Spine & Left Courtyard ---
    addDirectedEdge(15, 36, 30, graph); // Plaza (2nd) -> Central Spine Junction (30m)
    addDirectedEdge(36, 8, 35, graph);  // Central Spine Junction -> Central Corridor (35m)

    addDirectedEdge(9, 17, 50, graph);  // Library (b) -> Inventory Room (b) (50m)
    addDirectedEdge(17, 18, 30, graph); // Inventory Room (b) -> Auditorium (b) (30m)
    addDirectedEdge(18, 19, 35, graph); // Auditorium (b) -> EEE Lab (b) (35m)
    addDirectedEdge(8, 19, 30, graph);  // Central Corridor -> EEE Lab (b) (30m)
    addDirectedEdge(19, 37, 45, graph); // EEE Lab (b) -> South-East Junction (45m)

    // --- 8. Top-Right Academic Building Wing ---
    addDirectedEdge(36, 20, 40, graph); // Central Spine Junction -> Girls Common Room (40m)
    addDirectedEdge(20, 21, 45, graph); // Girls Common Room -> CR Center (45m)
    addDirectedEdge(36, 22, 35, graph); // Central Spine Junction -> American Corner (2nd) (35m)
    addDirectedEdge(22, 21, 40, graph); // American Corner (2nd) -> CR Center (40m)

    // --- 9. Bottom-Right Wing & Offices ---
    addDirectedEdge(8, 23, 25, graph);  // Central Corridor -> NCC Bank (25m)
    addDirectedEdge(23, 22, 30, graph); // NCC Bank -> American Corner (2nd) (30m)
    addDirectedEdge(23, 25, 35, graph); // NCC Bank -> BBA Dept (2nd) (35m)

    addDirectedEdge(8, 24, 30, graph);  // Central Corridor -> CSE Faculty (30m)
    addDirectedEdge(24, 25, 25, graph); // CSE Faculty -> BBA Dept (2nd) (25m)
    addDirectedEdge(25, 27, 25, graph); // BBA Dept (2nd) -> Lift (25m)

    addDirectedEdge(21, 26, 35, graph); // CR Center -> EEE Prog. Office (35m)
    addDirectedEdge(26, 27, 20, graph); // EEE Prog. Office -> Lift (20m)
    addDirectedEdge(27, 38, 20, graph); // Lift -> East Corridor Junction (20m)
    addDirectedEdge(38, 28, 20, graph); // East Corridor Junction -> CSE Prog. Office (20m)

    // --- 10. Parking & Medical Loop ---
    addDirectedEdge(25, 29, 30, graph); // BBA Dept (2nd) -> Parking (30m)
    addDirectedEdge(29, 30, 15, graph); // Parking -> Medical (15m)
    addDirectedEdge(30, 38, 35, graph); // Medical -> East Corridor Junction (35m)
    addDirectedEdge(37, 29, 30, graph); // South-East Junction -> Parking (30m)
    addDirectedEdge(8, 37, 45, graph);  // Central Corridor -> South-East Junction (45m)

    // --- 11. Right Side Gates to Garden & Canteen ---
    addDirectedEdge(21, 31, 35, graph); // CR Center -> Top-Right Gate (35m)
    addDirectedEdge(31, 35, 45, graph); // Top-Right Gate -> Top-Right Junction (45m)
    addDirectedEdge(38, 32, 30, graph); // East Corridor Junction -> Bottom-Right Gate (30m)
    addDirectedEdge(32, 7, 40, graph);  // Bottom-Right Gate -> Canteen (40m)

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
        // Only expose actual campus locations (0 to 32) to the dropdowns
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
                {{"id", 32}, {"name", "Gate (Bottom-Right)"}}
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