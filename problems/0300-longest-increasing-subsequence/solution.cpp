// 300. Longest Increasing Subsequence [Medium]
// https://leetcode.com/problems/longest-increasing-subsequence/
// Language: C++ | Runtime: 0 ms | Memory: 14.1 MB

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(int num : nums){
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if(it == tails.end()){
                tails.push_back(num);
            }else{
                *it = num;
            }
        }
        return tails.size();
    }
};
