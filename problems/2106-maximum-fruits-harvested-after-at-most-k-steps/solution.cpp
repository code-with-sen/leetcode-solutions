// 2106. Maximum Fruits Harvested After at Most K Steps [Hard]
// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/
// Language: C++ | Runtime: 51 ms | Memory: 187.8 MB

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // Build prefix sum array over all feasible positions
        int maxPos = max(startPos, fruits.back()[0]);
        vector<int> amounts(maxPos + 1, 0), prefix(maxPos + 2, 0);
        for (auto &f : fruits) {
            amounts[f[0]] = f[1];
        }
        for (int i = 0; i <= maxPos; ++i) {
            prefix[i+1] = prefix[i] + amounts[i];
        }

        auto getFruits = [&](int leftSteps, int rightSteps) -> int {
            int l = max(0, startPos - leftSteps);
            int r = min(maxPos, startPos + rightSteps);
            return prefix[r+1] - prefix[l];
        };

        int ans = 0;
        // Option 1: go right first, then maybe turn left
        int maxRightSteps = min(k, maxPos - startPos);
        for (int rs = 0; rs <= maxRightSteps; ++rs) {
            int ls = max(0, k - 2 * rs);
            ans = max(ans, getFruits(ls, rs));
        }
        // Option 2: go left first, then maybe turn right
        int maxLeftSteps = min(k, startPos);
        for (int ls = 0; ls <= maxLeftSteps; ++ls) {
            int rs = max(0, k - 2 * ls);
            ans = max(ans, getFruits(ls, rs));
        }
        return ans;
    }
};
