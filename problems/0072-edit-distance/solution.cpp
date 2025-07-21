// 72. Edit Distance [Medium]
// https://leetcode.com/problems/edit-distance/
// Language: C++ | Runtime: 7 ms | Memory: 13.2 MB

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases
        for (int i = 0; i <= m; i++)
            dp[i][0] = i; // Delete all characters from word1
        for (int j = 0; j <= n; j++)
            dp[0][j] = j; // Insert all characters to word1

        // Fill the table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // characters match
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],    // delete
                        dp[i][j - 1],    // insert
                        dp[i - 1][j - 1] // replace
                    });
                }
            }
        }

        return dp[m][n];
    }
};
