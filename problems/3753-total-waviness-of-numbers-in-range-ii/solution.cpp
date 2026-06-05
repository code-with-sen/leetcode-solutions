// 3753. Total Waviness of Numbers in Range II [Hard]
// https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/
// Language: C++ | Runtime: 19 ms | Memory: 10.1 MB

class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[17][11][11];
    bool vis[17][11][11];

    Node dfs(int pos, bool tight, int last2, int last1) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][last2][last1]) {
            return dp[pos][last2][last1];
        }

        int limit = tight ? (s[pos] - '0') : 9;
        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            int nlast2, nlast1;
            long long add = 0;

            if (last1 == 10) {
                // Still in leading zeros
                if (d == 0) {
                    nlast2 = 10;
                    nlast1 = 10;
                } else {
                    nlast2 = 10;
                    nlast1 = d;
                }
            }
            else if (last2 == 10) {
                // First actual digit already exists
                nlast2 = last1;
                nlast1 = d;
            }
            else {
                // Check if last1 is a peak or valley
                if ((last1 > last2 && last1 > d) ||
                    (last1 < last2 && last1 < d)) {
                    add = 1;
                }

                nlast2 = last1;
                nlast1 = d;
            }

            Node child = dfs(pos + 1, ntight, nlast2, nlast1);

            res.cnt += child.cnt;
            res.wav += child.wav + add * child.cnt;
        }

        if (!tight) {
            vis[pos][last2][last1] = true;
            dp[pos][last2][last1] = res;
        }

        return res;
    }

    long long solve(long long N) {
        if (N < 0) return 0;

        s = to_string(N);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, 10, 10).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
