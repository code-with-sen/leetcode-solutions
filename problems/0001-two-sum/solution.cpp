// 1. Two Sum [Easy]
// https://leetcode.com/problems/two-sum/
// Language: C++ | Runtime: 2 ms | Memory: 14.7 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];

            if (seen.find(needed) != seen.end()) {
                return {seen[needed], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};
