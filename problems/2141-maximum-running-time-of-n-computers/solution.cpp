// 2141. Maximum Running Time of N Computers [Hard]
// https://leetcode.com/problems/maximum-running-time-of-n-computers/
// Language: C++ | Runtime: 25 ms | Memory: 59.8 MB

class Solution {
 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    long sum = accumulate(batteries.begin(), batteries.end(), 0L);

    ranges::sort(batteries);

    // The maximum battery is greater than the average, so it can last forever.
    // Reduce the problem from size n to size n - 1.
    while (batteries.back() > sum / n) {
      sum -= batteries.back(), batteries.pop_back();
      --n;
    }

    // If the maximum battery <= average running time, it won't be waste, and so
    // do smaller batteries.
    return sum / n;
  }
};
