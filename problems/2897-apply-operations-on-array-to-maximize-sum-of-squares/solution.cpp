// 2897. Apply Operations on Array to Maximize Sum of Squares [Hard]
// https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/
// Language: C++ | Runtime: 51 ms | Memory: 90.7 MB

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int bits[31] = {};

        for (int x : nums)
            for (int b = 0; b < 31; b++)
                if (x & (1 << b)) bits[b]++;

        long long ans = 0;

        while (k--) {
            long long x = 0;
            for (int b = 0; b < 31; b++)
                if (bits[b] > 0)
                    x |= (1LL << b), bits[b]--;

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};
