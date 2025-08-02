// 2561. Rearranging Fruits [Hard]
// https://leetcode.com/problems/rearranging-fruits/
// Language: C++ | Runtime: 61 ms | Memory: 90.7 MB

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        for (int num : basket1) freq[num]++;
        for (int num : basket2) freq[num]--;

        vector<int> excess;
        int minValue = INT_MAX;

        for (auto& [val, count] : freq) {
            if (count % 2 != 0) return -1; // Odd difference means not possible
            for (int i = 0; i < abs(count) / 2; ++i)
                excess.push_back(val);

            minValue = min(minValue, val);
        }

        sort(excess.begin(), excess.end());

        long long cost = 0;
        int n = excess.size();
        for (int i = 0; i < n / 2; ++i) {
            cost += min(2LL * minValue, (long long)excess[i]);
        }

        return cost;
    }
};
