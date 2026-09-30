// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings [Medium]
// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
// Language: C++ | Runtime: 2 ms | Memory: 10.5 MB

class Solution {
public:
    vector<int> maxDepthAfterSplit(auto s) {
        int n = s.size(); vector<int> res(n);
        
        for (int i = 0; i < n; i++)
            res[i] = (i ^ s[i]) & 1;

        return res;
    }
};
