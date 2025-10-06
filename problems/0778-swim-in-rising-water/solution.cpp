// 778. Swim in Rising Water [Hard]
// https://leetcode.com/problems/swim-in-rising-water/
// Language: C++ | Runtime: 19 ms | Memory: 17.3 MB

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // Min-heap: stores {height, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int res = 0;

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int h = cur[0], x = cur[1], y = cur[2];

            if (visited[x][y]) continue;
            visited[x][y] = 1;
            res = max(res, h);

            if (x == n - 1 && y == n - 1) return res;

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }

        return -1; // should never reach here
    }
};
