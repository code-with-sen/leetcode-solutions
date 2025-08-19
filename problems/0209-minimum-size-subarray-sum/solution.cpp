// 209. Minimum Size Subarray Sum [Medium]
// https://leetcode.com/problems/minimum-size-subarray-sum/
// Language: C++ | Runtime: 0 ms | Memory: 32 MB

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0 ;
        long long sum = 0;
        int minLen = INT_MAX;
        for(int right = 0 ; right < n ; right++){
            sum += nums[right];

           while(sum >= target ){
            minLen = min(minLen , right - left + 1);
            sum -= nums[left];
            left++;
           } 
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
