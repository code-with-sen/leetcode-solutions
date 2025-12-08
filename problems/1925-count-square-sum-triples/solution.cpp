// 1925. Count Square Sum Triples [Easy]
// https://leetcode.com/problems/count-square-sum-triples/
// Language: C++ | Runtime: 28 ms | Memory: 9 MB

class Solution {
 public:
  int countTriples(int n) {
    int ans = 0;
    unordered_set<int> squared;

    for (int i = 1; i <= n; ++i)
      squared.insert(i * i);

    for (const int a : squared)
      for (const int b : squared)
        if (squared.contains(a + b))
          ++ans;

    return ans;
  }
};
