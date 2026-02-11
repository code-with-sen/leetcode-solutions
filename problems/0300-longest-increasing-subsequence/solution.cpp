// 300. Longest Increasing Subsequence [Medium]
// https://leetcode.com/problems/longest-increasing-subsequence/
// Language: C++ | Runtime: 3 ms | Memory: 14.1 MB

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
         for(int x : nums){
            auto it = lower_bound(tails.begin(), tails.end(), x);
           if( it == tails.end())
                tails.push_back(x);
            else
                *it = x;
        }
        return tails.size();
    }
};
