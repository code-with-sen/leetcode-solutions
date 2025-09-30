// 2221. Find Triangular Sum of an Array [Medium]
// https://leetcode.com/problems/find-triangular-sum-of-an-array/
// Language: C++ | Runtime: 54 ms | Memory: 22.2 MB

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        // Keep reducing the array until only one element remains
        for(int i = n - 1; i > 0; i--) {
            for(int j = 0; j < i; j++) {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }
        return nums[0];
    }
};
