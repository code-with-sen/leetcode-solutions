// 1021. Remove Outermost Parentheses [Easy]
// https://leetcode.com/problems/remove-outermost-parentheses/
// Language: C++ | Runtime: 0 ms | Memory: 8.9 MB

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int lvl = 0;
        
        for (auto& c : s)
            if ((c == '(' && lvl++) || (c == ')' && lvl-- > 1))
                res += c;

        return res;
    }
};
