// 3719. Longest Balanced Subarray I [Medium]
// https://leetcode.com/problems/longest-balanced-subarray-i/
// Language: C++ | Runtime: 1923 ms | Memory: 522.2 MB


class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            int even = 0, odd = 0;

            for (int j = i; j < n; j++) {
                // count only distinct elements
                if (seen.insert(nums[j]).second) {
                    if (nums[j] % 2 == 0)
                        even++;
                    else
                        odd++;
                }

                if (even == odd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
