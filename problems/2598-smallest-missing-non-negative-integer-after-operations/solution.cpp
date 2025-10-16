// 2598. Smallest Missing Non-negative Integer After Operations [Medium]
// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
// Language: C++ | Runtime: 67 ms | Memory: 135.7 MB

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int> freq;

        // Step 1: Count frequencies of nums[i] % value (handle negatives)
        for (int x : nums) {
            int r = ((x % value) + value) % value;
            freq[r]++;
        }

        // Step 2: The smallest missing non-negative integer
        // corresponds to the first number whose remainder count is minimal.
        int ans = 0;
        while (true) {
            int r = ans % value;
            if (freq[r] == 0) break;
            freq[r]--;
            ans++;
        }
        return ans;
    }
};
