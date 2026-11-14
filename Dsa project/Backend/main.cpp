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
int vertex = 41; // 34 Campus Locations + 7 Junctions (P1-P5 & Outer Corners)
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

    /*
     * Campus Locations (0 to 33):
     * 0: Main Gate, 1: Gate 2, 2: Gate 3, 3: Bus Stand, 4: Play Ground 1,
     * 5: Play Ground 2, 6: Garden, 7: Canteen, 8: Central Corridor,
     * 9: Library (b), 10: Gate (Top-Left), 11: Info Desk, 12: Boys Common Room (b),
     * 13: Mosque (2nd), 14: Pharmacy Dept (b), 15: Plaza (2nd), 16: Sinat (3rd),
     * 17: Inventory Room (b), 18: Auditorium (b), 19: EEE Lab (b), 20: Girls Common Room,
     * 21: CR Center, 22: American Corner (2nd), 23: NCC Bank, 24: CSE Faculty,
     * 25: BBA Dept (2nd), 26: EEE Prog. Office, 27: Lift, 28: CSE Prog. Office,
     * 29: Parking, 30: Medical, 31: Gate (Top-Right), 32: Gate (Bottom-Right), 33: Stair
     *
     * Junctions (34 to 40 - Excluded from Dropdown):
     * 34: P1, 35: P2, 36: P3, 37: P4, 38: P5, 39: Top-Left Curve, 40: Top-Right Curve
     */

    // 1. Bottom Outer Road
    addUndirectedEdge(0, 1, 90, graph); // Main Gate <-> Gate 2
    addDirectedEdge(0, 2, 140, graph);  // Main Gate -> Gate 3

    // 2. Left & Top Outer Perimeter
    addDirectedEdge(1, 3, 100, graph);   // Gate 2 -> Bus Stand
    addUndirectedEdge(3, 39, 50, graph); // Bus Stand <-> Top-Left Curve
    addUndirectedEdge(39, 4, 90, graph); // Top-Left Curve <-> Play Ground 1
    addUndirectedEdge(4, 5, 160, graph); // Play Ground 1 <-> Play Ground 2

    // 3. Right Outer Perimeter
    addDirectedEdge(2, 7, 110, graph);   // Gate 3 -> Canteen
    addUndirectedEdge(7, 6, 80, graph);  // Canteen <-> Garden
    addUndirectedEdge(6, 40, 40, graph); // Garden <-> Top-Right Curve
    addUndirectedEdge(40, 5, 40, graph); // Top-Right Curve <-> Play Ground 2

    // 4. Main Gate (0) & Gate 2 (1) to P3 (36)
    addDirectedEdge(0, 36, 30, graph); // Main Gate -> P3
    addDirectedEdge(1, 36, 90, graph); // Gate 2 -> P3

    // 5. P3 (36) -> P4 (37) -> Bus Stand (3) (Routes 31-42)
    addUndirectedEdge(36, 37, 60, graph); // P3 <-> P4
    addUndirectedEdge(37, 3, 70, graph);  // P4 <-> Bus Stand

    // 6. P3 (36) -> P5 (38) -> Stair (33) & Parking (29) (Routes 21-22, 43-61)
    addUndirectedEdge(36, 38, 30, graph); // P3 <-> P5
    addUndirectedEdge(38, 33, 30, graph); // P5 <-> Stair
    addUndirectedEdge(38, 29, 50, graph); // P5 <-> Parking

    // 7. Main Gate (0) & Gate 2 (1) Direct Curve to NCC Bank (23) (Routes 1-20, 63-68, 80)
    addDirectedEdge(0, 23, 60, graph);  // Main Gate -> NCC Bank
    addDirectedEdge(1, 23, 110, graph); // Gate 2 -> NCC Bank

    // 8. NCC Bank (23) & CSE Faculty (24) Connections
    addUndirectedEdge(23, 24, 20, graph); // NCC Bank <-> CSE Faculty
    addUndirectedEdge(23, 25, 30, graph); // NCC Bank <-> BBA Dept
    addUndirectedEdge(24, 25, 20, graph); // CSE Faculty <-> BBA Dept
    addUndirectedEdge(24, 29, 40, graph); // CSE Faculty <-> Parking
    addUndirectedEdge(24, 28, 50, graph); // CSE Faculty <-> CSE Prog. Office

    // 9. CSE Faculty (24) -> P1 (34) -> P2 (35) -> EEE Lab (19) & Library (9)
    addUndirectedEdge(24, 34, 30, graph); // CSE Faculty <-> P1
    addUndirectedEdge(34, 35, 40, graph); // P1 <-> P2
    addUndirectedEdge(35, 19, 20, graph); // P2 <-> EEE Lab
    addUndirectedEdge(35, 9, 30, graph);  // P2 <-> Library

    // 10. Left Courtyard Loop
    addUndirectedEdge(9, 17, 50, graph);  // Library <-> Inventory Room
    addUndirectedEdge(17, 18, 30, graph); // Inventory Room <-> Auditorium
    addUndirectedEdge(18, 19, 40, graph); // Auditorium <-> EEE Lab
    addUndirectedEdge(17, 12, 40, graph); // Inventory Room <-> Boys Common Room

    // 11. Bus Stand (3) to Top-Left Gate (10), Plaza (15), Girls Common (20)
    addUndirectedEdge(39, 10, 40, graph); // Top-Left Curve <-> Gate (Top-Left)
    addUndirectedEdge(3, 15, 90, graph);  // Bus Stand <-> Plaza
    addUndirectedEdge(3, 20, 120, graph); // Bus Stand <-> Girls Common Room

    // 12. Top-Left Wing
    addUndirectedEdge(10, 11, 30, graph); // Gate <-> Info Desk
    addUndirectedEdge(11, 13, 40, graph); // Info Desk <-> Mosque
    addUndirectedEdge(13, 14, 20, graph); // Mosque <-> Pharmacy Dept
    addUndirectedEdge(14, 15, 30, graph); // Pharmacy Dept <-> Plaza
    addUndirectedEdge(13, 15, 50, graph); // Mosque <-> Plaza

    addUndirectedEdge(11, 12, 30, graph); // Info Desk <-> Boys Common Room
    addUndirectedEdge(12, 14, 40, graph); // Boys Common Room <-> Pharmacy Dept
    addUndirectedEdge(12, 16, 30, graph); // Boys Common Room <-> Sinat
    addUndirectedEdge(16, 15, 30, graph); // Sinat <-> Plaza

    // 13. Central Spine
    addUndirectedEdge(33, 8, 30, graph); // Stair <-> Central Corridor
    addUndirectedEdge(8, 15, 40, graph); // Central Corridor <-> Plaza

    // 14. Top-Right Wing
    addUndirectedEdge(14, 20, 50, graph); // Pharmacy Dept <-> Girls Common Room
    addUndirectedEdge(20, 21, 50, graph); // Girls Common Room <-> CR Center
    addUndirectedEdge(15, 22, 40, graph); // Plaza <-> American Corner
    addUndirectedEdge(22, 25, 50, graph); // American Corner <-> BBA Dept

    // 15. East Wing Offices, Lift, Parking & Medical
    addUndirectedEdge(21, 26, 40, graph); // CR Center <-> EEE Prog. Office
    addUndirectedEdge(26, 27, 20, graph); // EEE Prog. Office <-> Lift
    addUndirectedEdge(27, 28, 20, graph); // Lift <-> CSE Prog. Office

    addUndirectedEdge(29, 30, 20, graph); // Parking <-> Medical
    addUndirectedEdge(29, 28, 30, graph); // Parking <-> CSE Prog. Office

    // 16. Right Side Gates to Garden & Canteen
    addUndirectedEdge(21, 31, 40, graph); // CR Center <-> Gate (Top-Right)
    addUndirectedEdge(31, 40, 50, graph); // Gate (Top-Right) <-> Top-Right Curve
    addUndirectedEdge(31, 7, 60, graph);  // Gate (Top-Right) <-> Canteen

    addUndirectedEdge(28, 32, 30, graph); // CSE Prog. Office <-> Gate (Bottom-Right)
    addUndirectedEdge(32, 7, 40, graph);  // Gate (Bottom-Right) <-> Canteen

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
        // Only actual campus locations (0-33) are returned; P1-P5 (34-38) are excluded
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