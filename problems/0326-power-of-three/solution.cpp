// 326. Power of Three [Easy]
// https://leetcode.com/problems/power-of-three/
// Language: C++ | Runtime: 11 ms | Memory: 8.9 MB

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};
