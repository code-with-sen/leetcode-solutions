// 283. Move Zeroes [Easy]
// https://leetcode.com/problems/move-zeroes/
// Language: C++ | Runtime: 0 ms | Memory: 23.7 MB

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzero = 0 ;
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i] != 0){
                nums[nonzero++] = nums[i];
            }
        }

        for(int i = nonzero ; i< nums.size();i++){
            nums[i] = 0;
        }
    }
};
