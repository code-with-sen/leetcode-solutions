// 808. Soup Servings [Medium]
// https://leetcode.com/problems/soup-servings/
// Language: C++ | Runtime: 8 ms | Memory: 14.3 MB

class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0; // Optimized threshold

        // dp[a][b] = probability A empties first (plus 0.5 if both at same time)
        unordered_map<int, unordered_map<int, double>> memo;

        function<double(int, int)> dp = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5;
            if (a <= 0) return 1.0;
            if (b <= 0) return 0.0;

            if (memo[a].count(b)) return memo[a][b];

            double res = 0.25 * (
                dp(a - 4, b) +
                dp(a - 3, b - 1) +
                dp(a - 2, b - 2) +
                dp(a - 1, b - 3)
            );

            memo[a][b] = res;
            return res;
        };

        int scaledN = (n + 24) / 25; // ceil(n / 25.0)
        return dp(scaledN, scaledN);
    }
};
