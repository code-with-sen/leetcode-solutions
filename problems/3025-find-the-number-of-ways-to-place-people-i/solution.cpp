// 3025. Find the Number of Ways to Place People I [Medium]
// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/
// Language: C++ | Runtime: 3 ms | Memory: 32.4 MB

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // sort by x asc, y desc
        sort(points.begin(), points.end(),
             [](const auto& a, const auto& b){
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] > b[1];
             });

        int n = points.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                if (points[i][1] >= points[j][1] && points[j][1] > maxY) {
                    ++ans;
                    maxY = points[j][1];
                }
            }
        }
        return ans;
    }
};
