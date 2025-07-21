// 55. Jump Game [Medium]
// https://leetcode.com/problems/jump-game/
// Language: C++ | Runtime: 0 ms | Memory: 52.1 MB

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for (int i = 0; i < nums.size();i++){
            if( i > reachable ) return false;
            reachable = max(reachable,i+nums[i]);
        }
        return true ;
    }
};
