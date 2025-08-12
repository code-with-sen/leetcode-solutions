// 2787. Ways to Express an Integer as Sum of Powers [Medium]
// https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/
// Language: C++ | Runtime: 16 ms | Memory: 11.7 MB

class Solution {
public:
    int numberOfWays(int n, int x) {
        constexpr int MOD = 1'000'000'007;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // There's exactly one way to sum up to 0: choose no numbers

        for (int a = 1; ; ++a) {
            long long pow_val = 1;
            for (int i = 0; i < x; ++i) pow_val *= a;
            if (pow_val > n) break;  // No need to continue if power exceeds n

            for (int j = n; j >= pow_val; --j) {
                dp[j] = (dp[j] + dp[j - pow_val]) % MOD;
            }
        }

        return dp[n];
    }
};
