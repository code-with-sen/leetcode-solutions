// 807. Max Increase to Keep City Skyline [Medium]
// https://leetcode.com/problems/max-increase-to-keep-city-skyline/
// Language: C++ | Runtime: 0 ms | Memory: 13.8 MB

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxRow(n, 0);
        vector<int> maxCol(n, 0);

        // Step 1: Compute row-wise and column-wise maximums
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxCol[j] = max(maxCol[j], grid[i][j]);
            }
        }

        int totalIncrease = 0;

        // Step 2: For each building, compute how much we can increase
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                int allowedHeight = min(maxRow[i], maxCol[j]);
                totalIncrease += (allowedHeight - grid[i][j]);
            }
        }

        return totalIncrease;
    }
};
