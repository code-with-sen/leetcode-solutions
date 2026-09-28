// 1614. Maximum Nesting Depth of the Parentheses [Easy]
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Language: C++ | Runtime: 0 ms | Memory: 8.5 MB

class Solution {
public:
    int maxDepth(std::string s) {
        int depth = 0;
        int r = 0;
        for (char c : s) {
            if (c == ')') {
                depth--;
                continue;
            }
            // Digits and operators
            if (c != '(') continue;
            depth++;
            // New max only possible after '('
            if (depth > r) r = depth;
        }
        return r;
    }
};
