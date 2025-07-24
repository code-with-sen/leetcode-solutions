// 2322. Minimum Score After Removals on a Tree [Hard]
// https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/
// Language: C++ | Runtime: 230 ms | Memory: 18.5 MB

class Solution {
public:
    vector<vector<int>> tree;
    vector<int> subtreeXor;

    int dfs(int node, int parent, vector<int>& nums) {
        int result = nums[node];
        for (int neighbor : tree[node]) {
            if (neighbor == parent) continue;
            result ^= dfs(neighbor, node, nums);
        }
        subtreeXor[node] = result;
        return result;
    }

    void dfsRecord(int node, int parent, vector<int>& inTime, vector<int>& outTime, int& timer) {
        inTime[node] = timer++;
        for (int neighbor : tree[node]) {
            if (neighbor == parent) continue;
            dfsRecord(neighbor, node, inTime, outTime, timer);
        }
        outTime[node] = timer;
    }

    bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime) {
        return inTime[u] <= inTime[v] && outTime[v] <= outTime[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.assign(n, {});
        subtreeXor.resize(n);

        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        dfs(0, -1, nums);

        vector<int> inTime(n), outTime(n);
        int timer = 0;
        dfsRecord(0, -1, inTime, outTime, timer);

        int totalXor = subtreeXor[0];
        int res = INT_MAX;

        // Try all pairs of edges: we treat each edge as child->parent node
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (i == j) continue;

                int a = i, b = j;
                int x, y, z;

                if (isAncestor(a, b, inTime, outTime)) {
                    x = subtreeXor[b];
                    y = subtreeXor[a] ^ subtreeXor[b];
                    z = totalXor ^ subtreeXor[a];
                } else if (isAncestor(b, a, inTime, outTime)) {
                    x = subtreeXor[a];
                    y = subtreeXor[b] ^ subtreeXor[a];
                    z = totalXor ^ subtreeXor[b];
                } else {
                    x = subtreeXor[a];
                    y = subtreeXor[b];
                    z = totalXor ^ x ^ y;
                }

                res = min(res, max({x, y, z}) - min({x, y, z}));
            }
        }

        return res;
    }
};
