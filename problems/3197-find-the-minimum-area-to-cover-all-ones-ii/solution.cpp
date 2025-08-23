// 3197. Find the Minimum Area to Cover All Ones II [Hard]
// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/
// Language: C++ | Runtime: 62 ms | Memory: 24.9 MB

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = m * n;
        
        // Explore horizontal-first partitions
        // Split grid by row i, then split lower part by column j
        for (int i = 0; i < m; ++i) {
            int top = minimumArea(grid, 0, i, 0, n - 1);
            for (int j = 0; j < n; ++j) {
                ans = min(ans,
                          top
                          + minimumArea(grid, i + 1, m - 1, 0, j)
                          + minimumArea(grid, i + 1, m - 1, j + 1, n - 1));
            }
        }
        
        // Split by bottom part, then vertical partitions
        for (int i = 0; i < m; ++i) {
            int bottom = minimumArea(grid, i, m - 1, 0, n - 1);
            for (int j = 0; j < n; ++j) {
                ans = min(ans,
                          bottom
                          + minimumArea(grid, 0, i - 1, 0, j)
                          + minimumArea(grid, 0, i - 1, j + 1, n - 1));
            }
        }
        
        // Vertical-first: partition by column j, then split remaining part by row i
        for (int j = 0; j < n; ++j) {
            int left = minimumArea(grid, 0, m - 1, 0, j);
            for (int i = 0; i < m; ++i) {
                ans = min(ans,
                          left
                          + minimumArea(grid, 0, i, j + 1, n - 1)
                          + minimumArea(grid, i + 1, m - 1, j + 1, n - 1));
            }
        }
        
        // Similarly, right-first then split
        for (int j = 0; j < n; ++j) {
            int right = minimumArea(grid, 0, m - 1, j, n - 1);
            for (int i = 0; i < m; ++i) {
                ans = min(ans,
                          right
                          + minimumArea(grid, 0, i, 0, j - 1)
                          + minimumArea(grid, i + 1, m - 1, 0, j - 1));
            }
        }
        
        // Splitting into three horizontal stripes
        for (int i1 = 0; i1 < m; ++i1) {
            for (int i2 = i1 + 1; i2 < m; ++i2) {
                ans = min(ans,
                          minimumArea(grid, 0, i1, 0, n - 1)
                          + minimumArea(grid, i1 + 1, i2, 0, n - 1)
                          + minimumArea(grid, i2 + 1, m - 1, 0, n - 1));
            }
        }
        
        // Splitting into three vertical stripes
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = j1 + 1; j2 < n; ++j2) {
                ans = min(ans,
                          minimumArea(grid, 0, m - 1, 0, j1)
                          + minimumArea(grid, 0, m - 1, j1 + 1, j2)
                          + minimumArea(grid, 0, m - 1, j2 + 1, n - 1));
            }
        }
        
        return ans;
    }

private:
    // Return area of smallest rectangle covering all 1s in subgrid
    int minimumArea(vector<vector<int>>& grid,
                    int si, int ei, int sj, int ej) {
        int min_i = INT_MAX, min_j = INT_MAX;
        int max_i = 0, max_j = 0;
        for (int i = si; i <= ei; ++i) {
            for (int j = sj; j <= ej; ++j) {
                if (grid[i][j] == 1) {
                    min_i = min(min_i, i);
                    min_j = min(min_j, j);
                    max_i = max(max_i, i);
                    max_j = max(max_j, j);
                }
            }
        }
        if (min_i == INT_MAX) return 0;  // No ones—area is zero
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
};
