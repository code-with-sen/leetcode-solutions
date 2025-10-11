// 3186. Maximum Total Damage With Spell Casting [Medium]
// https://leetcode.com/problems/maximum-total-damage-with-spell-casting/
// Language: C++ | Runtime: 295 ms | Memory: 212 MB

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> mp;
        for (int p : power) mp[p] += p; // total power for each unique spell

        vector<int> keys;
        for (auto& it : mp) keys.push_back(it.first);
        sort(keys.begin(), keys.end());

        int n = keys.size();
        vector<long long> dp(n);
        dp[0] = mp[keys[0]];

        for (int i = 1; i < n; i++) {
            long long include = mp[keys[i]];
            int j = i - 1;
            while (j >= 0 && keys[i] - keys[j] <= 2) j--; // skip interfering spells

            if (j >= 0) include += dp[j];
            dp[i] = max(dp[i - 1], include);
        }

        return dp[n - 1];
    }
};
