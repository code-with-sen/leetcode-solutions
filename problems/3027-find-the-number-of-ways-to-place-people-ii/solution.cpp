// 3027. Find the Number of Ways to Place People II [Hard]
// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/
// Language: C++ | Runtime: 125 ms | Memory: 41.2 MB

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Sort by x asc; for same x, by y desc
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] > b[1];
             });

        const int n = points.size();
        long long ans = 0; // safe if constraints are large

        for (int i = 0; i < n; ++i) {
            int maxY = INT_MIN; // best (highest) y among valid B's seen so far
            for (int j = i + 1; j < n; ++j) {
                // Bob must be to the right and not above Alice,
                // and we only count if his y is strictly greater than any previous candidate's y
                if (points[j][1] <= points[i][1] && points[j][1] > maxY) {
                    ++ans;
                    maxY = points[j][1];
                }
            }
        }
        return (int)ans;
    }
};
