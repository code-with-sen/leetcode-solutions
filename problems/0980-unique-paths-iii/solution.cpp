// 980. Unique Paths III [Hard]
// https://leetcode.com/problems/unique-paths-iii/
// Language: C++ | Runtime: 0 ms | Memory: 9.2 MB

class Solution {
public:
    int rows, cols;
    int totalNonObstacles = 0;
    int result = 0;

    void dfs(vector<vector<int>>& grid, int x, int y, int count) {
        // Out of bounds or obstacle
        if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == -1)
            return;

        // Reached end
        if (grid[x][y] == 2) {
            if (count == totalNonObstacles) result++;
            return;
        }

        int temp = grid[x][y];
        grid[x][y] = -1; // Mark visited

        // Move in 4 directions
        dfs(grid, x + 1, y, count + 1);
        dfs(grid, x - 1, y, count + 1);
        dfs(grid, x, y + 1, count + 1);
        dfs(grid, x, y - 1, count + 1);

        grid[x][y] = temp; // Backtrack
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int startX, startY;

        // Count total non-obstacles and find start point
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j] != -1) totalNonObstacles++;
                if (grid[i][j] == 1){
                    startX = i;
                    startY = j;
                }
            }
        }

        dfs(grid, startX, startY, 1); // count starts at 1 (starting cell)
        return result;
    }
};
