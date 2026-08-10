// 1510. Stone Game IV [Hard]
// https://leetcode.com/problems/stone-game-iv/
// Language: C++ | Runtime: 31 ms | Memory: 9 MB

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                if(!dp[i - j*j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return  dp[n];
    }
};
