// 407. Trapping Rain Water II [Hard]
// https://leetcode.com/problems/trapping-rain-water-ii/
// Language: C++ | Runtime: 25 ms | Memory: 18.6 MB

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        using Cell = tuple<int,int,int>; // {height, x, y}
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        // Push all boundary cells into heap
        for (int i = 0; i < m; i++) {
            pq.emplace(heightMap[i][0], i, 0);
            pq.emplace(heightMap[i][n - 1], i, n - 1);
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.emplace(heightMap[0][j], 0, j);
            pq.emplace(heightMap[m - 1][j], m - 1, j);
            visited[0][j] = visited[m - 1][j] = true;
        }

        int res = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};

        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k], ny = y + dirs[k+1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;

                visited[nx][ny] = true;
                // If neighbor is lower, water trapped = h - neighborHeight
                res += max(0, h - heightMap[nx][ny]);
                // Push max(h, neighborHeight) into heap
                pq.emplace(max(h, heightMap[nx][ny]), nx, ny);
            }
        }

        return res;
    }
};
