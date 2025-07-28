// 2044. Count Number of Maximum Bitwise-OR Subsets [Medium]
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
// Language: C++ | Runtime: 10 ms | Memory: 10.6 MB

class Solution {
public:
    int maxOR = 0, count = 0;

    void dfs(vector<int>& nums, int index, int currOR) {
        if (index == nums.size()) {
            if (currOR == maxOR) count++;
            return;
        }

        // Include current element
        dfs(nums, index + 1, currOR | nums[index]);

        // Exclude current element
        dfs(nums, index + 1, currOR);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (int num : nums) {
            maxOR |= num;
        }

        dfs(nums, 0, 0);
        return count;
    }
};
