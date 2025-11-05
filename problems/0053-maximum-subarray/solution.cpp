// 53. Maximum Subarray [Medium]
// https://leetcode.com/problems/maximum-subarray/
// Language: C++ | Runtime: 4 ms | Memory: 71.7 MB

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count = nums[0] , maxcount = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            count = max(nums[i] , nums[i] + count);
            maxcount = max(maxcount, count);
        }

        return maxcount;
        
    }
};
