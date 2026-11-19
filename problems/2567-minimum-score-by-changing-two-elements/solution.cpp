// 2567. Minimum Score by Changing Two Elements [Medium]
// https://leetcode.com/problems/minimum-score-by-changing-two-elements/
// Language: C++ | Runtime: 16 ms | Memory: 37.7 MB

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min({nums[n-1] - nums[2], nums[n-3] - nums[0], nums[n-2] - nums[1]});
    }
};
