// 3147. Taking Maximum Energy From the Mystic Dungeon [Medium]
// https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/
// Language: C++ | Runtime: 137 ms | Memory: 151.8 MB

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        int ans = INT_MIN;

        // Traverse from the back
        for (int i = n - 1; i >= 0; --i) {
            if (i + k < n)
                dp[i] = energy[i] + dp[i + k];
            else
                dp[i] = energy[i];

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
