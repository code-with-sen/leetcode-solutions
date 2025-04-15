// 238. Product of Array Except Self [Medium]
// https://leetcode.com/problems/product-of-array-except-self/
// Language: C++ | Runtime: 0 ms | Memory: 40.1 MB

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        // First pass: prefix product
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        // Second pass: suffix product
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
