// 1358. Number of Substrings Containing All Three Characters [Medium]
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Language: C++ | Runtime: 14 ms | Memory: 11 MB

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int p[3] = {-1, -1, -1};

        for (int i = 0; i < s.length(); i++) {
            p[(s[i] & 31) - 1] = i;
            res += min({p[0], p[1], p[2]}) + 1;
        }

        return res;
    }
};
