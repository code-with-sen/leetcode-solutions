// 4122. Earliest Signal Activation Times [Medium]
// https://leetcode.com/problems/earliest-signal-activation-times/
// Language: C++ | Runtime: 601 ms | Memory: 446.9 MB


class Solution {
public:
    vector<long long> earliestActivationTimes(
        int n, vector<vector<int>>& edges, vector<int>& requiredSignals
    ) {
        vector<vector<pair<int, int>>> adj(n);
        vector<long long> ans(n, -1);

        auto navirelomu = make_tuple(n, edges, requiredSignals);

        for (auto &e : get<1>(navirelomu)) {
            int u = e[0], v = e[1], d = e[2];
            adj[u].push_back({v, d});
        }

        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        vector<int> received(n, 0);
        vector<bool> active(n, false);
        vector<unordered_set<int>> visited(n);

        ans[0] = 0;
        active[0] = true;

        for (auto [v, d] : adj[0]) {
            pq.push({d, 0, v});
        }

        while (!pq.empty()) {
            auto [time, u, v] = pq.top();
            pq.pop();

            if (active[v]) continue;
            if (visited[v].count(u)) continue;

            visited[v].insert(u);
            received[v]++;

            if (received[v] >= requiredSignals[v]) {
                active[v] = true;
                ans[v] = time;

                for (auto [next, delay] : adj[v]) {
                    pq.push({time + delay, v, next});
                }
            }
        }

        return ans;
    }
};
