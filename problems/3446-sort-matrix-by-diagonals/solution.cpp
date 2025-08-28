// 3446. Sort Matrix by Diagonals [Medium]
// https://leetcode.com/problems/sort-matrix-by-diagonals/
// Language: C++ | Runtime: 11 ms | Memory: 46.2 MB

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diag;

        // 1) Collect elements by diagonal key (i - j)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                diag[i - j].push_back(grid[i][j]);

        // 2) Sort each diagonal:
        //    key < 0  -> top-right triangle -> ascending
        //    key >= 0 -> bottom-left (incl. main) -> descending
        for (auto& [key, v] : diag) {
            if (key < 0) sort(v.begin(), v.end());
            else         sort(v.begin(), v.end(), greater<int>());
        }

        // 3) Refill in natural diagonal order (top-left to bottom-right),
        //    consuming from the FRONT of each sorted list
        unordered_map<int, int> idx;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int key = i - j;
                grid[i][j] = diag[key][idx[key]++];
            }

        return grid;
    }
};
