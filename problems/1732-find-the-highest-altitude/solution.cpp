// 1732. Find the Highest Altitude [Easy]
// https://leetcode.com/problems/find-the-highest-altitude/
// Language: C++ | Runtime: 0 ms | Memory: 10.7 MB

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, sum = 0;

        for (auto& it : gain) {
            sum += it;
            int d = sum - ans;
            ans += d & ~(d >> 0x1F);
        }

        return ans;
    }
};
