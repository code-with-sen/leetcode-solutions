// 3014. Minimum Number of Pushes to Type Word I [Easy]
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
// Language: C++ | Runtime: 0 ms | Memory: 8.2 MB

class Solution {
public:
    int minimumPushes(string A) {
        auto q = A.size() >> 3, r = A.size() & 7;
        return ((q << 2) + r) * (q + 1);
    }
};
