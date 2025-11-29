// 3512. Minimum Operations to Make Array Sum Divisible by K [Easy]
// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
// Language: C++ | Runtime: 0 ms | Memory: 45.2 MB

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    return accumulate(nums.begin(), nums.end(), 0) % k;
  }
};
