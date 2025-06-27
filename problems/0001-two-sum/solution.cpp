// 1. Two Sum [Easy]
// https://leetcode.com/problems/two-sum/
// Language: C++ | Runtime: 0 ms | Memory: 14.9 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (map.find(complement) != map.end()) {
                return {map[complement], i}; // Return indices
            }

            map[nums[i]] = i; // Store current value with index
        }

        return {}; // If no pair found
    }
};
