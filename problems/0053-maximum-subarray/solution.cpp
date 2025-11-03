// 53. Maximum Subarray [Medium]
// https://leetcode.com/problems/maximum-subarray/
// Language: C++ | Runtime: 0 ms | Memory: 71.6 MB

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count = nums[0] , maxcount = nums[0]; // dono ek sath starting pr hai
        for(int i = 1 ; i < nums.size() ; i++){
            count = max(nums[i] , nums[i] + count); // ek ek add kro aur max lao 
            maxcount = max(maxcount , count); //last mei sbse large series lao
        }
        return maxcount; // sbse large yehi mila 
    }
};
