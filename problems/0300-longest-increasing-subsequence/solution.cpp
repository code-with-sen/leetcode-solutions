// 300. Longest Increasing Subsequence [Medium]
// https://leetcode.com/problems/longest-increasing-subsequence/
// Language: C++ | Runtime: 67 ms | Memory: 14.2 MB

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 1);
        int maxlength = 1;

        for(int i = 1; i< n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){
                    dp [i]=  max(dp[i], dp[j] + 1);
                }
            }

            maxlength = max(maxlength, dp[i]);
        }

        return maxlength;
        
    }
};
