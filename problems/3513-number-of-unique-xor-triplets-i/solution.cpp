// 3513. Number of Unique XOR Triplets I [Medium]
// https://leetcode.com/problems/number-of-unique-xor-triplets-i/
// Language: C++ | Runtime: 0 ms | Memory: 198.7 MB

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        size_t n = nums.size();
        return 1 << (bit_width(n) - 3 / (n + 1));
    }
};
