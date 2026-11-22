// 2124. Check if All A's Appears Before All B's [Easy]
// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
// Language: C++ | Runtime: 0 ms | Memory: 8.3 MB

class Solution {
public:
    bool checkString(string s) {
        return s.find("ba") == string::npos;
    }
};
