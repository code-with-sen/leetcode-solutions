// 1912. Design Movie Rental System [Hard]
// https://leetcode.com/problems/design-movie-rental-system/
// Language: C++ | Runtime: 235 ms | Memory: 402.7 MB


class MovieRentingSystem {
public:
    // (shop, movie) -> price
    unordered_map<long long, int> priceMap;

    // movie -> available shops (sorted by price, then shop)
    unordered_map<int, set<pair<int,int>>> available;

    // rented movies: (price, shop, movie)
    set<tuple<int,int,int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            long long key = ((long long)shop << 32) | movie;
            priceMap[key] = price;
            available[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (!available.count(movie)) return res;
        auto &s = available[movie];
        int cnt = 0;
        for (auto &p : s) {
            res.push_back(p.second);
            if (++cnt == 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        long long key = ((long long)shop << 32) | movie;
        int price = priceMap[key];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        long long key = ((long long)shop << 32) | movie;
        int price = priceMap[key];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto &t : rented) {
            int price, shop, movie;
            tie(price, shop, movie) = t;
            res.push_back({shop, movie});
            if (++cnt == 5) break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
