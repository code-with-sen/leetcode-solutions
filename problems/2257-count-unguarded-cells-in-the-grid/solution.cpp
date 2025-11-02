// 2257. Count Unguarded Cells in the Grid [Medium]
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
// Language: C++ | Runtime: 97 ms | Memory: 191.5 MB


class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 0 empty, 1 guard, 2 wall
        for (auto &g : guards) grid[g[0]][g[1]] = 1;
        for (auto &w : walls)  grid[w[0]][w[1]] = 2;

        vector<vector<bool>> watched(m, vector<bool>(n, false));
        const int dr[4] = {0, 0, 1, -1};
        const int dc[4] = {1, -1, 0, 0};

        for (auto &g : guards) {
            int gr = g[0], gc = g[1];
            for (int k = 0; k < 4; ++k) {
                int r = gr + dr[k], c = gc + dc[k];
                while (r >= 0 && r < m && c >= 0 && c < n) {
                    if (grid[r][c] == 2) break; // wall
                    if (grid[r][c] == 1) break; // guard blocks
                    watched[r][c] = true;
                    r += dr[k]; c += dc[k];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0 && !watched[i][j]) ++ans;
        return ans;
    }
};
