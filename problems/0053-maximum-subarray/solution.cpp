// 53. Maximum Subarray [Medium]
// https://leetcode.com/problems/maximum-subarray/
// Language: C++ | Runtime: 0 ms | Memory: 71.7 MB

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0,max = INT_MIN;
        for(int i = 0 ; i< n ; i++){
            sum += nums[i];
            if(sum > max){
                max = sum;
            }if(sum<0){
                sum = 0;
            }
        }
        return max;
    }
};
