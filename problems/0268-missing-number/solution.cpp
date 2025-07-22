// 268. Missing Number [Easy]
// https://leetcode.com/problems/missing-number/
// Language: C++ | Runtime: 0 ms | Memory: 21.9 MB

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorall = 0, xornums = 0 ;
        int n = nums.size();

        for(int i = 0 ; i <= n ; i++){
            xorall ^= i;
        }

        for(int num : nums){
            xornums ^= num;
        }

        return xorall^xornums;
    }
};
