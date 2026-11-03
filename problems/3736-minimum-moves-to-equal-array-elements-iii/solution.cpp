// 3736. Minimum Moves to Equal Array Elements III [Easy]
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
// Language: C++ | Runtime: 0 ms | Memory: 31.6 MB

class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long int sum = 0;
        for(auto it : nums) sum += it;
        int mx = *max_element(nums.begin(), nums.end());
        return nums.size() * mx - sum;
    }
};
