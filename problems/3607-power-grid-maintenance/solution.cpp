// 3607. Power Grid Maintenance [Medium]
// https://leetcode.com/problems/power-grid-maintenance/
// Language: C++ | Runtime: 219 ms | Memory: 353.3 MB


class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n + 1);
        rankv.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rankv[x] < rankv[y]) swap(x, y);
        parent[y] = x;
        if (rankv[x] == rankv[y]) rankv[x]++;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        
        // Step 1: Build connected components
        for (auto &con : connections) {
            dsu.unite(con[0], con[1]);
        }

        // Step 2: Maintain online sets for each component
        unordered_map<int, set<int>> compOnline;
        vector<bool> online(c + 1, true);

        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            compOnline[root].insert(i);
        }

        vector<int> ans;

        // Step 3: Process each query
        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];
            int root = dsu.find(x);

            if (type == 1) {
                // find nearest online station
                if (online[x]) {
                    ans.push_back(x);
                } else if (!compOnline[root].empty()) {
                    ans.push_back(*compOnline[root].begin());
                } else {
                    ans.push_back(-1);
                }
            } 
            else if (type == 2) {
                // make offline
                if (online[x]) {
                    online[x] = false;
                    compOnline[root].erase(x);
                }
            }
        }

        return ans;
    }
};
