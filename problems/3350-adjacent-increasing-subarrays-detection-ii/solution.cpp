// 3350. Adjacent Increasing Subarrays Detection II [Medium]
// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/
// Language: C++ | Runtime: 216 ms | Memory: 173.5 MB

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int pre = 0, cur = 0;
        
        for (int i = 0; i < n; ++i) {
            ++cur;
            // if this is the last element or sequence breaks
            if (i == n - 1 || nums[i] >= nums[i + 1]) {
                // two possibilities:
                // 1. split current strictly increasing run into two adjacent subarrays → cur/2
                // 2. take tail of previous run + head of current → min(pre, cur)
                ans = max(ans, max(cur / 2, min(pre, cur)));
                pre = cur;
                cur = 0;
            }
        }
        
        return ans;
    }
};
