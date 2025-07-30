// 922. Sort Array By Parity II [Easy]
// https://leetcode.com/problems/sort-array-by-parity-ii/
// Language: C++ | Runtime: 0 ms | Memory: 25.8 MB

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0; // Even index
        int j = 1; // Odd index

        while (i < n && j < n) {
            if (nums[i] % 2 == 0) {
                i += 2; // Correct place for even
            } else if (nums[j] % 2 == 1) {
                j += 2; // Correct place for odd
            } else {
                // Swap incorrect elements
                swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }
        }

        return nums;
    }
};
