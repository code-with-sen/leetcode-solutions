// 2300. Successful Pairs of Spells and Potions [Medium]
// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
// Language: C++ | Runtime: 38 ms | Memory: 125 MB



class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            long long required = (success + spells[i] - 1) / spells[i]; // ceil division
            int idx = lower_bound(potions.begin(), potions.end(), required) - potions.begin();
            ans[i] = m - idx;
        }
        return ans;
    }
};
