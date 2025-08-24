// 136. Single Number [Easy]
// https://leetcode.com/problems/single-number/
// Language: C++ | Runtime: 0 ms | Memory: 20.6 MB

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0 ;
        for(int i = 0 ; i < nums.size();i++){
            xorr^=nums[i];
        }

        return xorr;
    }
};
