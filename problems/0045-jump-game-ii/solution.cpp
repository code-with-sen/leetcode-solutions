// 45. Jump Game II [Medium]
// https://leetcode.com/problems/jump-game-ii/
// Language: C++ | Runtime: 0 ms | Memory: 20.5 MB

class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0 , farthest = 0 , end = 0 ;
        for(int i = 0 ; i < nums.size()-1 ; i ++){
            farthest = max(farthest , i + nums[i]);
            if(i == end ){
                jump++;
                end = farthest ;
            }
        }
        return jump;
    }
};
