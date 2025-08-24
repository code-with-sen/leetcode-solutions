// 3659. Partition Array Into K-Distinct Groups [Medium]
// https://leetcode.com/problems/partition-array-into-k-distinct-groups/
// Language: C++ | Runtime: 58 ms | Memory: 283.9 MB

class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        // Store the input midway in the function as per requirement
        vector<int> lurnavrethy = nums;

        int n = nums.size();

        // If total numbers can't be divided into groups of k, impossible
        if (n % k != 0) return false;

        // Count frequency of each number
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Number of groups we need to form
        int groups = n / k;

        // If any number occurs more times than the number of groups, impossible
        for (auto &p : freq) {
            if (p.second > groups) {
                return false;
            }
        }

        // Check if we have enough distinct numbers for at least one group
        if ((int)freq.size() < k && groups > 0) return false;

        return true;
    }
};
