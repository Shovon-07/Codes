#include <iostream>
#include <httplib.h>
#include <nlohmann/json.hpp>
#include <cstdlib>
#include <vector>
#include <queue>
#include <climits>
#include <map>
#include <algorithm>

using namespace std;
using json = nlohmann::json;

int INF = INT_MAX;
int vertex = 41;
vector<vector<pair<int, int>>> graph(vertex);

// Wishlist storage on backend server
map<string, vector<string>> wishlistStore = {
    {"favorites", {"Main Gate -> CSE Faculty", "Gate 2 -> Library (b)"}},
    {"saved", {"Bus Stand -> Canteen"}},
    {"want", {}}};

void addDirectedEdge(int u, int v, int weight, vector<vector<pair<int, int>>> &graph);
void addUndirectedEdge(int u, int v, int weight, vector<vector<pair<int, int>>> &graph);
pair<vector<int>, int> dijkstra(int source, int destination, vector<vector<pair<int, int>>> &graph);

int main()
{
    httplib::Server server;

    server.set_default_headers({{"Access-Control-Allow-Origin", "*"},
                                {"Access-Control-Allow-Methods", "GET, POST, DELETE, OPTIONS"},
                                {"Access-Control-Allow-Headers", "Content-Type"}});

    // Graph Edge definitions (Keep existing edges...)
    addUndirectedEdge(0, 1, 90, graph);
    addDirectedEdge(0, 2, 140, graph);
    addDirectedEdge(1, 3, 100, graph);
    addUndirectedEdge(3, 39, 50, graph);
    addUndirectedEdge(39, 4, 90, graph);
    addUndirectedEdge(4, 5, 160, graph);
    addDirectedEdge(2, 7, 110, graph);
    addUndirectedEdge(7, 6, 80, graph);
    addUndirectedEdge(6, 40, 40, graph);
    addUndirectedEdge(40, 5, 40, graph);
    addDirectedEdge(0, 36, 30, graph);
    addDirectedEdge(1, 36, 90, graph);
    addUndirectedEdge(36, 37, 60, graph);
    addUndirectedEdge(37, 3, 70, graph);
    addUndirectedEdge(36, 38, 30, graph);
    addUndirectedEdge(38, 33, 30, graph);
    addUndirectedEdge(38, 29, 50, graph);
    addDirectedEdge(0, 23, 60, graph);
    addDirectedEdge(1, 23, 110, graph);
    addUndirectedEdge(23, 24, 20, graph);
    addUndirectedEdge(23, 25, 30, graph);
    addUndirectedEdge(24, 25, 20, graph);
    addUndirectedEdge(24, 29, 40, graph);
    addUndirectedEdge(24, 28, 50, graph);
    addUndirectedEdge(24, 34, 30, graph);
    addUndirectedEdge(34, 35, 40, graph);
    addUndirectedEdge(35, 19, 20, graph);
    addUndirectedEdge(35, 9, 30, graph);
    addUndirectedEdge(9, 17, 50, graph);
    addUndirectedEdge(17, 18, 30, graph);
    addUndirectedEdge(18, 19, 40, graph);
    addUndirectedEdge(17, 12, 40, graph);
    addUndirectedEdge(39, 10, 40, graph);
    addUndirectedEdge(3, 15, 90, graph);
    addUndirectedEdge(3, 20, 120, graph);
    addUndirectedEdge(10, 11, 30, graph);
    addUndirectedEdge(11, 13, 40, graph);
    addUndirectedEdge(13, 14, 20, graph);
    addUndirectedEdge(14, 15, 30, graph);
    addUndirectedEdge(13, 15, 50, graph);
    addUndirectedEdge(11, 12, 30, graph);
    addUndirectedEdge(12, 14, 40, graph);
    addUndirectedEdge(12, 16, 30, graph);
    addUndirectedEdge(16, 15, 30, graph);
    addUndirectedEdge(33, 8, 30, graph);
    addUndirectedEdge(8, 15, 40, graph);
    addUndirectedEdge(14, 20, 50, graph);
    addUndirectedEdge(20, 21, 50, graph);
    addUndirectedEdge(15, 22, 40, graph);
    addUndirectedEdge(22, 25, 50, graph);
    addUndirectedEdge(21, 26, 40, graph);
    addUndirectedEdge(26, 27, 20, graph);
    addUndirectedEdge(27, 28, 20, graph);
    addUndirectedEdge(29, 30, 20, graph);
    addUndirectedEdge(29, 28, 30, graph);
    addUndirectedEdge(21, 31, 40, graph);
    addUndirectedEdge(31, 40, 50, graph);
    addUndirectedEdge(31, 7, 60, graph);
    addUndirectedEdge(28, 32, 30, graph);
    addUndirectedEdge(32, 7, 40, graph);

    // --- Wishlist API Endpoints ---
    server.Options("/wishlist", [](const httplib::Request &req, httplib::Response &res)
                   { res.status = 204; });

    // GET /wishlist?tab=favorites
    server.Get("/wishlist", [](const httplib::Request &req, httplib::Response &res)
               {
        string tab = req.has_param("tab") ? req.get_param_value("tab") : "favorites";
        json items = json::array();
        if (wishlistStore.find(tab) != wishlistStore.end()) {
            items = wishlistStore[tab];
        }
        json response = {{"tab", tab}, {"items", items}};
        res.set_content(response.dump(), "application/json"); });

    // POST /wishlist (Add item)
    server.Post("/wishlist", [](const httplib::Request &req, httplib::Response &res)
                {
        try {
            json data = json::parse(req.body);
            string tab = data.at("tab").get<string>();
            string item = data.at("item").get<string>();
            if (wishlistStore.find(tab) != wishlistStore.end()) {
                auto &vec = wishlistStore[tab];
                if (find(vec.begin(), vec.end(), item) == vec.end()) {
                    vec.push_back(item);
                }
            }
            res.set_content(R"({"success":true})", "application/json");
        } catch (...) {
            res.status = 400;
            res.set_content(R"({"error":"Invalid input"})", "application/json");
        } });

    // DELETE /wishlist (Remove item by index)
    server.Delete("/wishlist", [](const httplib::Request &req, httplib::Response &res)
                  {
        try {
            json data = json::parse(req.body);
            string tab = data.at("tab").get<string>();
            int index = data.at("index").get<int>();
            if (wishlistStore.find(tab) != wishlistStore.end()) {
                auto &vec = wishlistStore[tab];
                if (index >= 0 && index < vec.size()) {
                    vec.erase(vec.begin() + index);
                }
            }
            res.set_content(R"({"success":true})", "application/json");
        } catch (...) {
            res.status = 400;
            res.set_content(R"({"error":"Invalid input"})", "application/json");
        } });

    // Existing Path & Location Endpoints
    server.Options("/find-path", [](const httplib::Request &req, httplib::Response &res)
                   { res.status = 204; });

    server.Post("/find-path", [](const httplib::Request &req, httplib::Response &res)
                {
        try {
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
        } catch (const exception &e) {
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