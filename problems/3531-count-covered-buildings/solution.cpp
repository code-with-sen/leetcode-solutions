// 3531. Count Covered Buildings [Medium]
// https://leetcode.com/problems/count-covered-buildings/
// Language: C++ | Runtime: 415 ms | Memory: 354.5 MB

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        if (buildings.size() < 5) {
            return 0;
        }

        unordered_map<int, int> row_min;
        unordered_map<int, int> row_max;
        unordered_map<int, int> col_min;
        unordered_map<int, int> col_max;

        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            if (row_min.find(x) == row_min.end()) {
                row_min[x] = y;
                row_max[x] = y;
            } else {
                row_min[x] = min(row_min[x], y);
                row_max[x] = max(row_max[x], y);
            }

            if (col_min.find(y) == col_min.end()) {
                col_min[y] = x;
                col_max[y] = x;
            } else {
                col_min[y] = min(col_min[y], x);
                col_max[y] = max(col_max[y], x);
            }
        }

        int covered_count = 0;
        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            bool has_horizontal_cover = false;
            if (row_min.find(x) != row_min.end() && row_max.find(x) != row_max.end()) {
              has_horizontal_cover = (row_min[x] < y && y < row_max[x]);
            }

            bool has_vertical_cover = false;
            if (col_min.find(y) != col_min.end() && col_max.find(y) != col_max.end()) {
              has_vertical_cover = (col_min[y] < x && x < col_max[y]);
            }

            if (has_horizontal_cover && has_vertical_cover) {
                covered_count++;
            }
        }

        return covered_count;
    }
};
