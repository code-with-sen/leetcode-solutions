// 837. New 21 Game [Medium]
// https://leetcode.com/problems/new-21-game/
// Language: C++ | Runtime: 4 ms | Memory: 14.7 MB

class Solution {
public:
    double new21Game(int N, int K, int W) {
        // If we never need to draw, or even the maximum possible final score is <= N, win prob is 1
        if (K == 0 || N >= K + W - 1) return 1.0;

        // dp[i] = probability of winning (final score <= N) starting from current sum = i
        // When i >= K, game stops immediately: win if i <= N, else lose.
        vector<double> dp(N + W + 1, 0.0);
        for (int i = K; i <= N; ++i) dp[i] = 1.0;

        // Initialize sliding window: sum of dp[i+1..i+W] when i = K-1 => dp[K..K+W-1]
        double windowSum = 0.0;
        for (int i = K; i < K + W; ++i) windowSum += dp[i];

        // Fill dp from K-1 down to 0
        for (int i = K - 1; i >= 0; --i) {
            dp[i] = windowSum / W;                     // average of next W states
            windowSum += dp[i] - dp[i + W];            // slide the window left by 1
        }
        return dp[0];
    }
};
