// 1190. Reverse Substrings Between Each Pair of Parentheses [Medium]
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Language: C++ | Runtime: 0 ms | Memory: 9 MB

class Solution { 
public: 
    string reverseParentheses(string s) { 
        int n = s.size();
        vector<int> pair(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                int j = st.top(); st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string res;
        int i = 0, dir = 1;
        while (i >= 0 && i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                dir = -dir;
            } else {
                res += s[i];
            }
            i += dir;
        }
        return res;
    } 
};
