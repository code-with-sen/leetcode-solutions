// 1513. Number of Substrings With Only 1s [Medium]
// https://leetcode.com/problems/number-of-substrings-with-only-1s/
// Language: C++ | Runtime: 4 ms | Memory: 11.6 MB

class Solution {
public:
    int numSub(string s) {
        long long count = 0, result = 0;
        long long mod = 1e9 + 7;

        for (char c : s) {
            if (c == '1') {
                count++;
            } else {
                result = (result + (count * (count + 1) / 2)) % mod;
                count = 0;
            }
        }
        
        result = (result + (count * (count + 1) / 2)) % mod;
        return result;
    }
};
