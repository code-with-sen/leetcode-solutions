// 417. Pacific Atlantic Water Flow [Medium]
// https://leetcode.com/problems/pacific-atlantic-water-flow/
// Language: C++ | Runtime: 8 ms | Memory: 23.6 MB

class Solution {
public:
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};

        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        // DFS from ocean edges
        for (int i = 0; i < m; ++i) {
            dfs(heights, pac, i, 0, heights[i][0]);        // Pacific (left)
            dfs(heights, atl, i, n - 1, heights[i][n - 1]); // Atlantic (right)
        }

        for (int j = 0; j < n; ++j) {
            dfs(heights, pac, 0, j, heights[0][j]);        // Pacific (top)
            dfs(heights, atl, m - 1, j, heights[m - 1][j]); // Atlantic (bottom)
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && atl[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }

    void dfs(vector<vector<int>>& h, vector<vector<int>>& visited, int i, int j, int prevHeight) {
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        if (visited[i][j]) return;
        if (h[i][j] < prevHeight) return;

        visited[i][j] = 1;

        dfs(h, visited, i + 1, j, h[i][j]);
        dfs(h, visited, i - 1, j, h[i][j]);
        dfs(h, visited, i, j + 1, h[i][j]);
        dfs(h, visited, i, j - 1, h[i][j]);
    }
};
