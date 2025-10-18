// 3397. Maximum Number of Distinct Elements After Operations [Medium]
// https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/
// Language: C++ | Runtime: 100 ms | Memory: 97.5 MB

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long occupied = LLONG_MIN/4; // last assigned value (very small initially)
        int ans = 0;
        for (int num : nums) {
            // if even the max possible value num + k is <= occupied, we cannot place a new distinct value
            if (occupied < (long long)num + k) {
                // choose the smallest unused value >= num-k and > occupied
                long long pick = max(occupied + 1, (long long)num - k);
                // pick must be <= num + k (guaranteed by the if condition)
                occupied = pick;
                ++ans;
            }
        }
        return ans;
    }
};
