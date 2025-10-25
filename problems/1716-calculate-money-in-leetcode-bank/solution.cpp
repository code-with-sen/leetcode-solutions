// 1716. Calculate Money in Leetcode Bank [Easy]
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/
// Language: C++ | Runtime: 0 ms | Memory: 7.9 MB

class Solution {
public:
    int totalMoney(int n) {
        int w = n / 7;
        int r = n % 7;
        long long full = 28LL * w + (7LL * w * (w - 1)) / 2; // safe in long long
        long long start = 1 + w;
        long long rem = 1LL * r * start + (1LL * r * (r - 1)) / 2;
        return (int)(full + rem);
    }
};
