// 268. Missing Number [Easy]
// https://leetcode.com/problems/missing-number/
// Language: C++ | Runtime: 0 ms | Memory: 21.9 MB

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int xor1 = 0 , xor2 = 0;

        for(int i = 0 ; i < nums.size(); i++){
            xor1 ^= nums[i];
            xor2 ^= (i + 1);
        }

        return xor1^xor2;
    }
};
