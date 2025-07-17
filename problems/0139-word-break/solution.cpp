// 139. Word Break [Medium]
// https://leetcode.com/problems/word-break/
// Language: C++ | Runtime: 11 ms | Memory: 16.2 MB

class Solution {
public:
    bool wordBreak(string s, vector<string>& word) {
        unordered_set<string> dict(word.begin(), word.end());
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i = 1 ; i<= n ; i++){
            for (int j = 0 ; j < i ; j++){
                if(dp[j] && dict.find(s.substr(j ,i - j)) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
