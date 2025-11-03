// 1578. Minimum Time to Make Rope Colorful [Medium]
// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
// Language: C++ | Runtime: 3 ms | Memory: 100 MB

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total = 0;
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i-1]) {
                total += min(neededTime[i], neededTime[i-1]);
                neededTime[i] = max(neededTime[i], neededTime[i-1]);
            }
        }
        return total;
    }
};
