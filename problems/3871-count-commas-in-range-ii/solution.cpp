// 3871. Count Commas in Range II [Medium]
// https://leetcode.com/problems/count-commas-in-range-ii/
// Language: C++ | Runtime: 0 ms | Memory: 8.9 MB

class Solution {
public:
    int64_t countCommas(auto& n) {
        int64_t count = 0;
        for (int64_t p = 1000; p <= n; p *= 1000)
            count += n - p + 1;

        return count;
    }
};
