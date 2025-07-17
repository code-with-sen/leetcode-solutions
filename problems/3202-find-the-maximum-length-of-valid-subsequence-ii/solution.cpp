// 3202. Find the Maximum Length of Valid Subsequence II [Medium]
// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/
// Language: C++ | Runtime: 101 ms | Memory: 128.9 MB

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size(), answer = 1;
        // Try all possible (sub[i] + sub[i+1]) % k = val
        for (int val = 0; val < k; ++val) {
            vector<int> dp(k, 0);  // dp[r] = max length ending with remainder r
            for (int x : nums) {
                int r = x % k;
                int prev = (val - r + k) % k;
                dp[r] = max(dp[r], dp[prev] + 1);
                answer = max(answer, dp[r]);
            }
        }
        return answer;
    }
};
