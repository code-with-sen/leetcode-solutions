// 136. Single Number [Easy]
// https://leetcode.com/problems/single-number/
// Language: C++ | Runtime: 0 ms | Memory: 20.7 MB

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int val : nums){
            ans^= val;
        }

        return ans;
    }
};
