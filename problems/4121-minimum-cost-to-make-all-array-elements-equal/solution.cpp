// 4121. Minimum Cost to Make All Array Elements Equal [Medium]
// https://leetcode.com/problems/minimum-cost-to-make-all-array-elements-equal/
// Language: C++ | Runtime: 3 ms | Memory: 208.2 MB


class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) return 0;

        long long ans = LLONG_MAX;
        int i = 0;

        while (i < n) {
            int j = i;

            while (j + 1 < n && nums[j] == nums[j + 1]) {
                j++;
            }

            if (j >= 1 && i <= n - 2) {
                long long cost = 1LL * (i + n - 1 - j) * nums[i];
                ans = min(ans, cost);
            }

            i = j + 1;
        }

        return ans;
    }
};
