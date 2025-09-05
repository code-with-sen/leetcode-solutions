// 2749. Minimum Operations to Make the Integer Zero [Medium]
// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/
// Language: C++ | Runtime: 0 ms | Memory: 8.2 MB

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 60; ++k) {
            long long x = (long long)num1 - k * (long long)num2;
            if (x >= k && __builtin_popcountll(x) <= k) return (int)k;
        }
        return -1;
    }
};
