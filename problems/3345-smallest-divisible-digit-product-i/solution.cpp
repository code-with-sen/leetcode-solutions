// 3345. Smallest Divisible Digit Product I [Easy]
// https://leetcode.com/problems/smallest-divisible-digit-product-i/
// Language: C++ | Runtime: 0 ms | Memory: 8.6 MB

class Solution {
public:
    int smallestNumber(int n, int t) {
        auto [q, r] = div(n, 10);

        int req = t / gcd(q + (10 - q) / 10, t);
        int nxt = ((r + req - 1) / req) * req;
        int x = nxt - (nxt - 10) * (nxt / 10);

        return q * 10 + x;
    }
};
