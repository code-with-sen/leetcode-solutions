// 2770. Maximum Number of Jumps to Reach the Last Index [Medium]
// https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
// Language: C++ | Runtime: 15 ms | Memory: 68.6 MB

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        // dp[i] = maximum jumps needed to reach index i
        vector<int> dp(n, -1);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == -1)
                continue;

            for (int j = i + 1; j < n; j++) {
                long long diff = 1LL * nums[j] - nums[i];

                if (diff >= -target && diff <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
