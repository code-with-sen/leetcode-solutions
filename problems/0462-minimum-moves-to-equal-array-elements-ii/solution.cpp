// 462. Minimum Moves to Equal Array Elements II [Medium]
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Language: C++ | Runtime: 0 ms | Memory: 15.8 MB

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        long long moves = 0;
        for (int num : nums) {
            moves += abs(num - median);
        }
        return moves;
    }
};
