// 3201. Find the Maximum Length of Valid Subsequence I [Medium]
// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/
// Language: C++ | Runtime: 12 ms | Memory: 96.3 MB

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        int ans = 0;
        
        for (int num : nums) {
            num %= 2;  // Get parity (0 for even, 1 for odd)
            for (int i = 0; i < 2; i++) {
                dp[i][num] = dp[num][i] + 1;
                ans = max(ans, dp[i][num]);
            }
        }
        
        return ans;
    }
};
