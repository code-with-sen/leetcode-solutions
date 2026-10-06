// 921. Minimum Add to Make Parentheses Valid [Medium]
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Language: C++ | Runtime: 0 ms | Memory: 8.3 MB

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, add = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    add++;
                }
            }
        }
        return add + open;
    }
};
