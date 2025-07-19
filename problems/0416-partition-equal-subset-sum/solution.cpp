// 416. Partition Equal Subset Sum [Medium]
// https://leetcode.com/problems/partition-equal-subset-sum/
// Language: C++ | Runtime: 87 ms | Memory: 13.4 MB

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum = accumulate(nums.begin(), nums.end(),0);
        
        if(totalsum % 2 != 0 ) return false;

        int target = totalsum/2;
        int n = nums.size();

        vector<bool> dp(target + 1 , false);

        dp[0] = true;

        for(int num : nums){
        for ( int j = target ; j >= num ; j--){
            dp[j] = dp[j] || dp[j - num];
        }
        
        }
        return dp[target];
    }
};
