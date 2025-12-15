// 2110. Number of Smooth Descent Periods of a Stock [Medium]
// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
// Language: C++ | Runtime: 0 ms | Memory: 107.1 MB

class Solution {
 public:
  long long getDescentPeriods(vector<int>& prices) {
    long ans = 1;  // prices[0]
    int dp = 1;

    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] == prices[i - 1] - 1)
        ++dp;
      else
        dp = 1;
      ans += dp;
    }

    return ans;
  }
};
