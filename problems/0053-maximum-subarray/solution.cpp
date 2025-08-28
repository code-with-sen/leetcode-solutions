// 53. Maximum Subarray [Medium]
// https://leetcode.com/problems/maximum-subarray/
// Language: C++ | Runtime: 0 ms | Memory: 71.8 MB

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int count = nums[0];
        int maxcount = nums[0];
        for(int i = 1 ; i < n ; i++){
            count = max(nums[i],nums[i] +count);
            maxcount = max(maxcount,count);
        }

        return maxcount;
    }
};
