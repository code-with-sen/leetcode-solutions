// 231. Power of Two [Easy]
// https://leetcode.com/problems/power-of-two/
// Language: C++ | Runtime: 0 ms | Memory: 7.8 MB

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
