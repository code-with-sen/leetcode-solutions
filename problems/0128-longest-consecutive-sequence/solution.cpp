// 128. Longest Consecutive Sequence [Medium]
// https://leetcode.com/problems/longest-consecutive-sequence/
// Language: C++ | Runtime: 80 ms | Memory: 88.8 MB

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Start of a new sequence
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};
