// 3870. Count Commas in Range [Easy]
// https://leetcode.com/problems/count-commas-in-range/
// Language: C++ | Runtime: 0 ms | Memory: 8.5 MB

class Solution {
public:
    int countCommas(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (i >= 1000) {
                count++;
            }
        }

        return count;
    }
};
