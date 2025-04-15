// 53. Maximum Subarray [Medium]
// https://leetcode.com/problems/maximum-subarray/
// Language: C++ | Runtime: 1 ms | Memory: 71.9 MB

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0 , maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            sum += nums[i];
            if(sum>maxi){
                maxi = sum;
            }
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;
    }
};
