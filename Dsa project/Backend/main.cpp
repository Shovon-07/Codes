#define CPPHTTPLIB_IMPLEMENTATION
#include <iostream>
#include "httplib.h"
#include <nlohmann/json.hpp>
#include <cstdlib>
#include <vector>
#include "Graph.h"
#include "Wishlist.h"

using namespace std;
using json = nlohmann::json;

int main()
{
    httplib::Server server;
    WishlistManager wishlistManager;

    server.set_default_headers({{"Access-Control-Allow-Origin", "*"},
                                {"Access-Control-Allow-Methods", "GET, POST, DELETE, OPTIONS"},
                                {"Access-Control-Allow-Headers", "Content-Type"}});

    vector<vector<pair<int, int>>> graph(VERTEX_COUNT);
    initializeCampusGraph(graph);

    // --- Wishlist API Endpoints ---
    server.Options("/wishlist", [](const httplib::Request &req, httplib::Response &res)
                   { res.status = 204; });

    server.Get("/wishlist", [&wishlistManager](const httplib::Request &req, httplib::Response &res)
               {
        string tab = req.has_param("tab") ? req.get_param_value("tab") : "favorites";
        json items = wishlistManager.getItems(tab);
        json response = {{"tab", tab}, {"items", items}};
        res.set_content(response.dump(), "application/json"); });

    server.Post("/wishlist", [&wishlistManager](const httplib::Request &req, httplib::Response &res)
                {
        try {
            json data = json::parse(req.body);
            string tab = data.at("tab").get<string>();
            string item = data.at("item").get<string>();
            wishlistManager.addItem(tab, item);
            res.set_content(R"({"success":true})", "application/json");
        } catch (...) {
            res.status = 400;
            res.set_content(R"({"error":"Invalid input"})", "application/json");
        } });

    server.Delete("/wishlist", [&wishlistManager](const httplib::Request &req, httplib::Response &res)
                  {
        try {
            json data = json::parse(req.body);
            string tab = data.at("tab").get<string>();
            int index = data.at("index").get<int>();
            wishlistManager.removeItem(tab, index);
            res.set_content(R"({"success":true})", "application/json");
        } catch (...) {
            res.status = 400;
            res.set_content(R"({"error":"Invalid input"})", "application/json");
        } });

    // --- Path Finding & Location Endpoints ---
    server.Options("/find-path", [](const httplib::Request &req, httplib::Response &res)
                   { res.status = 204; });

    server.Post("/find-path", [&graph](const httplib::Request &req, httplib::Response &res)
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
        } catch (...) {
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
                // {{"id", 10}, {"name", "Gate (Top-Left)"}},
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
                // {{"id", 31}, {"name", "Gate (Top-Right)"}},
                // {{"id", 32}, {"name", "Gate (Bottom-Right)"}},
                {{"id", 33}, {"name", "Stair"}}
            }}
        };
        res.set_content(locations.dump(), "application/json"); });

    const char *envPort = getenv("PORT");
    int port = envPort ? stoi(envPort) : 8080;
    cout << "C++ Backend running on port " << port << '\n';
    server.listen("0.0.0.0", port);

    return 0;
}