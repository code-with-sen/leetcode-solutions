// 2327. Number of People Aware of a Secret [Medium]
// https://leetcode.com/problems/number-of-people-aware-of-a-secret/
// Language: C++ | Runtime: 0 ms | Memory: 9.4 MB

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1; // Day 1, one person knows
        long long share = 0;

        for (int day = 2; day <= n; day++) {
            // People start sharing after 'delay'
            if (day - delay >= 1) {
                share = (share + dp[day - delay]) % MOD;
            }
            // People stop sharing after 'forget'
            if (day - forget >= 1) {
                share = (share - dp[day - forget] + MOD) % MOD;
            }
            dp[day] = share;
        }

        long long ans = 0;
        // Count people who still remember on day n
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1)
                ans = (ans + dp[day]) % MOD;
        }
        return ans;
    }
};
