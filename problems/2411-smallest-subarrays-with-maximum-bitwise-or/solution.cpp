// 2411. Smallest Subarrays With Maximum Bitwise OR [Medium]
// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/
// Language: C++ | Runtime: 28 ms | Memory: 60.9 MB

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> lastBit(32, -1); // stores last seen index for each bit (0 to 31)

        for (int i = n - 1; i >= 0; --i) {
            // Update lastBit for each bit present in nums[i]
            for (int b = 0; b < 32; ++b) {
                if ((nums[i] >> b) & 1) {
                    lastBit[b] = i;
                }
            }

            int maxIndex = i;
            for (int b = 0; b < 32; ++b) {
                if (lastBit[b] != -1) {
                    maxIndex = max(maxIndex, lastBit[b]);
                }
            }

            ans[i] = maxIndex - i + 1;
        }

        return ans;
    }
};
