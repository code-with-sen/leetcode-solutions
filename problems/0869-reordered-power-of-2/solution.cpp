// 869. Reordered Power of 2 [Medium]
// https://leetcode.com/problems/reordered-power-of-2/
// Language: C++ | Runtime: 0 ms | Memory: 9 MB


class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        for (int i = 0; i < 31; i++) {
            int p = 1 << i;
            string t = to_string(p);
            sort(t.begin(), t.end());
            if (t == s) return true;
        }
        return false;
    }
};
