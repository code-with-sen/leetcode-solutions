// 128. Longest Consecutive Sequence [Medium]
// https://leetcode.com/problems/longest-consecutive-sequence/
// Language: C++ | Runtime: 83 ms | Memory: 88.9 MB

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(),nums.end());
        int longest = 0;
        for(int num:numset){
            if(!numset.contains(num - 1)){
                int numcurrent = num;
                int numstreak = 1;

                while(numset.contains(numcurrent +1)){
                    numcurrent += 1;
                    numstreak += 1;
                }
                 longest = max(longest , numstreak);
            }
           
        }
        return longest ;
    }
};
