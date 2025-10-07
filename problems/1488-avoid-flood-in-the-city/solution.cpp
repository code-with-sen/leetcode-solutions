// 1488. Avoid Flood in The City [Medium]
// https://leetcode.com/problems/avoid-flood-in-the-city/
// Language: C++ | Runtime: 115 ms | Memory: 114.6 MB

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);             // default: 1 for dry days
        unordered_map<int, int> last;      // last day when a lake got rain
        set<int> dryDays;                  // indices of dry days

        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                // dry day, store index
                dryDays.insert(i);
            } else {
                ans[i] = -1; // raining day
                if (last.count(lake)) {
                    int prevDay = last[lake];
                    // find dry day after last fill
                    auto it = dryDays.upper_bound(prevDay);
                    if (it == dryDays.end()) {
                        // no day available to dry before this rain -> flood
                        return {};
                    }
                    // assign that dry day to this lake
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                last[lake] = i; // update last fill day
            }
        }
        return ans;
    }
};
