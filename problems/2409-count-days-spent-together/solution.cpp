// 2409. Count Days Spent Together [Easy]
// https://leetcode.com/problems/count-days-spent-together/
// Language: C++ | Runtime: 0 ms | Memory: 7.8 MB

class Solution {
public:
    int countDaysTogether(string a, string b, string c, string d) {
        return max(0, min(f(b), f(d)) - max(f(a), f(c)) + 1);
    }

    int f(auto& s) {
        int m = (s[0] - '0') * 10 + (s[1] - '0');
        int q = (s[3] - '0') * 10 + (s[4] - '0');

        return (275 * m) / 9 - 30 - 2 * ((m + 9) / 12) + q;
    }
};
