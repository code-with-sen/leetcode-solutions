// 3480. Maximize Subarrays After Removing One Conflicting Pair [Hard]
// https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/
// Language: C++ | Runtime: 173 ms | Memory: 324.4 MB

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long valid = 0;
        int maxLeft = 0, secondMax = 0;
        vector<long long> gains(n + 2, 0);
        vector<vector<int>> conflicts(n + 2);
        
        // Group conflicts by right endpoint = max(a, b)
        for (auto &p : conflictingPairs) {
            int a = p[0], b = p[1];
            conflicts[max(a, b)].push_back(min(a, b));
        }
        
        // Iterate through each possible right endpoint of subarray
        for (int right = 1; right <= n; ++right) {
            for (int left : conflicts[right]) {
                if (left > maxLeft) {
                    secondMax = maxLeft;
                    maxLeft = left;
                } else if (left > secondMax) {
                    secondMax = left;
                }
            }
            // Subarrays from maxLeft+1 to right are valid
            valid += right - maxLeft;
            gains[maxLeft] += (maxLeft - secondMax);
        }
        
        long long bestGain = 0;
        for (int i = 1; i <= n; ++i) bestGain = max(bestGain, gains[i]);
        return valid + bestGain;
    }
};
