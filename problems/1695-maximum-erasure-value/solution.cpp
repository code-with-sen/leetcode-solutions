// 1695. Maximum Erasure Value [Medium]
// https://leetcode.com/problems/maximum-erasure-value/
// Language: C++ | Runtime: 194 ms | Memory: 131.2 MB

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, right = 0, sum = 0, maxSum = 0;

        while (right < nums.size()) {
            if (seen.find(nums[right]) == seen.end()) {
                sum += nums[right];
                seen.insert(nums[right]);
                maxSum = max(maxSum, sum);
                right++;
            } else {
                sum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }
        }

        return maxSum;
    }
};
