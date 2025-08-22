// 3195. Find the Minimum Area to Cover All Ones I [Medium]
// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
// Language: C++ | Runtime: 250 ms | Memory: 133.6 MB

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minRow = m, minCol = n;
        int maxRow = 0, maxCol = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    minCol = min(minCol, j);
                    maxRow = max(maxRow, i);
                    maxCol = max(maxCol, j);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
