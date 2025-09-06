// 3495. Minimum Operations to Make Array Elements Zero [Hard]
// https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/
// Language: C++ | Runtime: 22 ms | Memory: 183.6 MB


class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        // Precompute powers of 4 up to 1e9
        vector<long long> pow4 = {1};
        while (pow4.back() <= 1e9) {
            pow4.push_back(pow4.back() * 4);
        }

        long long totalOps = 0;

        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long steps = 0;

            for (int i = 1; i < pow4.size(); i++) {
                long long left = max(l, pow4[i - 1]);
                long long right = min(r, pow4[i] - 1);
                if (left > right) continue;

                long long count = right - left + 1;
                steps += count * i;
            }

            // Each operation reduces two numbers simultaneously
            totalOps += (steps + 1) / 2;
        }

        return totalOps;
    }
};
