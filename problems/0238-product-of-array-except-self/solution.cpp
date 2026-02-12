// 238. Product of Array Except Self [Medium]
// https://leetcode.com/problems/product-of-array-except-self/
// Language: C++ | Runtime: 4 ms | Memory: 40.2 MB

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        int prefix = 1;
        for(int i = 0 ; i < nums.size(); i++){
            ans[i] = prefix ;
            prefix *= nums[i];
        }

        int suffix = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            ans[i] *= suffix ;
            suffix *= nums[i];
        }

        return ans;
    }
};
