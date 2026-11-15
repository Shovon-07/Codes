#ifndef WISHLIST_H
#define WISHLIST_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class WishlistManager
{
private:
    map<string, vector<string>> wishlistStore;

public:
    WishlistManager()
    {
        wishlistStore = {
            {"favorites", {"Main Gate -> CSE Faculty", "Gate 2 -> Library (b)"}},
            {"saved", {"Bus Stand -> Canteen"}},
            {"want", {}}};
    }

    vector<string> getItems(const string &tab)
    {
        if (wishlistStore.find(tab) != wishlistStore.end())
        {
            return wishlistStore[tab];
        }
        return {};
    }

    void addItem(const string &tab, const string &item)
    {
        if (wishlistStore.find(tab) != wishlistStore.end())
        {
            auto &vec = wishlistStore[tab];
            if (find(vec.begin(), vec.end(), item) == vec.end())
            {
                vec.push_back(item);
            }
        }
    }

    void removeItem(const string &tab, int index)
    {
        if (wishlistStore.find(tab) != wishlistStore.end())
        {
            auto &vec = wishlistStore[tab];
            if (index >= 0 && index < vec.size())
            {
                vec.erase(vec.begin() + index);
            }
        }
    }
};

#endif