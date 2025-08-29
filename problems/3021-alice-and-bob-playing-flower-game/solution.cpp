// 3021. Alice and Bob Playing Flower Game [Medium]
// https://leetcode.com/problems/alice-and-bob-playing-flower-game/
// Language: C++ | Runtime: 3 ms | Memory: 8.4 MB

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long xEven = n / 2;
        long long xOdd  = (n + 1LL) / 2;
        long long yEven = m / 2;
        long long yOdd  = (m + 1LL) / 2;
        return xEven * yOdd + xOdd * yEven;
    }
};
