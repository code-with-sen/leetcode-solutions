// 1900. The Earliest and Latest Rounds Where Players Compete [Hard]
// https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/
// Language: C++ | Runtime: 3087 ms | Memory: 550.7 MB

class Solution {
public:
    int earliest = INT_MAX;
    int latest = 0;
    unordered_map<string, bool> seen;

    void backtrack(vector<int>& players, int first, int second, int round) {
        string key;
        for (int p : players) key += to_string(p) + ",";
        key += to_string(round);
        if (seen[key]) return;
        seen[key] = true;

        int n = players.size();
        for (int i = 0; i < n / 2; i++) {
            int a = players[i];
            int b = players[n - 1 - i];
            if ((a == first && b == second) || (a == second && b == first)) {
                earliest = min(earliest, round);
                latest = max(latest, round);
                return;
            }
        }

        vector<vector<int>> nextRounds;
        dfsMatch(players, 0, n - 1, {}, nextRounds, first, second);

        for (auto& next : nextRounds) {
            sort(next.begin(), next.end()); // maintain order
            backtrack(next, first, second, round + 1);
        }
    }

    void dfsMatch(vector<int>& players, int l, int r, vector<int> curr,
                  vector<vector<int>>& nextRounds, int first, int second) {
        if (l > r) {
            nextRounds.push_back(curr);
            return;
        }

        if (l == r) {
            curr.push_back(players[l]);
            nextRounds.push_back(curr);
            return;
        }

        int a = players[l];
        int b = players[r];

        if ((a == first && b == second) || (a == second && b == first)) {
            return; // if they meet, don't continue simulation
        }

        // if either is first/second, force them to win
        if (a == first || a == second) {
            curr.push_back(a);
            dfsMatch(players, l + 1, r - 1, curr, nextRounds, first, second);
            curr.pop_back();
        } else if (b == first || b == second) {
            curr.push_back(b);
            dfsMatch(players, l + 1, r - 1, curr, nextRounds, first, second);
            curr.pop_back();
        } else {
            // both players are normal, choose a to win
            curr.push_back(a);
            dfsMatch(players, l + 1, r - 1, curr, nextRounds, first, second);
            curr.pop_back();

            // or b wins
            curr.push_back(b);
            dfsMatch(players, l + 1, r - 1, curr, nextRounds, first, second);
            curr.pop_back();
        }
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> players;
        for (int i = 1; i <= n; i++) players.push_back(i);
        backtrack(players, firstPlayer, secondPlayer, 1);
        return {earliest, latest};
    }
};
