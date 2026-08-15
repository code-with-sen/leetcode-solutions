// 3702. Longest Subsequence With Non-Zero Bitwise XOR [Medium]
// https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
// Language: C++ | Runtime: 1 ms | Memory: 171.3 MB

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        auto tot = 0, nonZero = 0;

        for (auto& n : nums) {
            nonZero |= n > 0;
            tot ^= n;
        }

        return nonZero * (nums.size() - !tot);
    }
};
