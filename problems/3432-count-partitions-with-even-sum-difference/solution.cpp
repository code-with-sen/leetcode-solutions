// 3432. Count Partitions with Even Sum Difference [Easy]
// https://leetcode.com/problems/count-partitions-with-even-sum-difference/
// Language: C++ | Runtime: 0 ms | Memory: 22.6 MB

class Solution {
 public:
  int countPartitions(std::vector<int>& nums) {
    // If we add the same number in the left subarray and remove it from the
    // right subarray, then the difference remains the same parity. So, just
    // return the number of ways to partition the array into two subarrays when
    // the array sum is even.
    return accumulate(nums.begin(), nums.end(), 0) % 2 == 0 ? nums.size() - 1
                                                            : 0;
  }
};
