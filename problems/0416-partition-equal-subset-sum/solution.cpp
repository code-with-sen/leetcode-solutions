// 416. Partition Equal Subset Sum [Medium]
// https://leetcode.com/problems/partition-equal-subset-sum/
// Language: C++ | Runtime: 63 ms | Memory: 13.4 MB

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
        }

        return dp[target];
    }
};
