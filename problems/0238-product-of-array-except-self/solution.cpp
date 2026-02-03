// 238. Product of Array Except Self [Medium]
// https://leetcode.com/problems/product-of-array-except-self/
// Language: C++ | Runtime: 0 ms | Memory: 40.2 MB

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        int prefix = 1;  // prefix start se end tk jayega 
        for(int i = 0; i < n; i++){
            ans[i] = prefix;  // ans mei prefix then,
            prefix *= nums[i];  // prefix mei nums
        }

        int suffix = 1;    // suffix end se start tk ayega 
        for(int i = n - 1; i >= 0; i--){
            ans[i] *= suffix;  // ans mei * hoga suffix (end se aa rha hai)
            suffix *= nums[i];  // suffix mei nums ayega 
        }

        return ans;  // ans mei store ho chuka hai return kr do.
    }
};
