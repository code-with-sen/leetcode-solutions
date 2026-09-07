// 940. Distinct Subsequences II [Hard]
// https://leetcode.com/problems/distinct-subsequences-ii/
// Language: C++ | Runtime: 0 ms | Memory: 8.9 MB

class Solution {
    static constexpr int MOD = 1e9 + 7;

public:
    int distinctSubseqII(string s) {
        int tot = 0, dp[26]{};

        for (auto& c : s) {
            c -= 'a';
            int add = (tot - dp[c] + MOD) % MOD;
            dp[c] = 1 + tot;
            tot = (dp[c] + add) % MOD;
        }

        return tot;
    }
};
