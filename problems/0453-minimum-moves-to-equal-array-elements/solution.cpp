// 453. Minimum Moves to Equal Array Elements [Medium]
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Language: C++ | Runtime: 0 ms | Memory: 32.1 MB

class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0ll) - (nums.size() * ranges::min(nums));
    }
};
