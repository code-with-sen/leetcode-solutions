// 283. Move Zeroes [Easy]
// https://leetcode.com/problems/move-zeroes/
// Language: C++ | Runtime: 0 ms | Memory: 23.9 MB

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonzero= 0 ;

        for(int i = 0;i<n;i++){
            if(nums[i] != 0){
            nums[nonzero++] = nums[i];
        }
    }
     
     for(int i = nonzero;i<n;i++){
            nums[i] = 0;
        }
    }
};
