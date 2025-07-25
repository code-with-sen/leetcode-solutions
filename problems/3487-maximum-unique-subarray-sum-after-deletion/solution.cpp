// 3487. Maximum Unique Subarray Sum After Deletion [Easy]
// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/
// Language: C++ | Runtime: 4 ms | Memory: 29.5 MB

class Solution {
public:
    long long maxSum(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        if (mx <= 0) return mx;

        unordered_set<int> seen;
        long long total = 0;
        for (int x : nums) {
            if (x >= 0 && !seen.count(x)) {
                total += x;
                seen.insert(x);
            }
        }
        return total;
    }
};
