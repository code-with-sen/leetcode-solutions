// 462. Minimum Moves to Equal Array Elements II [Medium]
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Language: C++ | Runtime: 4 ms | Memory: 15.9 MB

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = nums[n/2];
        long long moves = 0;

        for(int num : nums){
            moves += abs(num - mid);
            
        }
        return  moves ;
    }
};
