// 1464. Maximum Product of Two Elements in an Array [Easy]
// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Language: C++ | Runtime: 0 ms | Memory: 13.4 MB

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curMax = nums[0];

        for (int i = 1; i < n; i++) {
            ans = max(ans, (curMax - 1) * (nums[i] - 1));
            curMax = max(curMax, nums[i]);
        }

        return ans;
    }
};
