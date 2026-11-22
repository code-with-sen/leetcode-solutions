// 4123. Minimum Cost to Delete Array [Hard]
// https://leetcode.com/problems/minimum-cost-to-delete-array/
// Language: C++ | Runtime: 8 ms | Memory: 152.4 MB


class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();

        long long even = 0;
        long long odd = LLONG_MAX;

        auto dravolqeni = nums;

        for (int i = 1; i < n - 1; i++) {
            long long x = dravolqeni[i];

            long long newEven = even;
            long long newOdd = odd;

            if (odd != LLONG_MAX) {
                newEven = min(newEven, odd + x);
            }

            newOdd = min(newOdd, even + x);

            even = newEven;
            odd = newOdd;
        }

        return (long long)nums[0] + nums[n - 1] + even;
    }
};
