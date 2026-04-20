// 3905. Multi Source Flood Fill [Medium]
// https://leetcode.com/problems/multi-source-flood-fill/
// Language: C++ | Runtime: 305 ms | Memory: 214.8 MB

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<int>> ans(n, vector<int>(m, 0));

        // {distance, color, row, col}
        priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<>> pq;

        // initialize sources
        for (auto &s : sources) {
            int r = s[0], c = s[1], color = s[2];
            dist[r][c] = 0;
            ans[r][c] = color;
            pq.push({0, -color, r, c}); // -color to simulate max color
        }

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [d, negColor, r, c] = pq.top();
            pq.pop();

            int color = -negColor;

            // skip outdated
            if (d > dist[r][c]) continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {

                    if (dist[nr][nc] > d + 1) {
                        dist[nr][nc] = d + 1;
                        ans[nr][nc] = color;
                        pq.push({d + 1, -color, nr, nc});
                    }
                    else if (dist[nr][nc] == d + 1) {
                        // same time → take max color
                        if (ans[nr][nc] < color) {
                            ans[nr][nc] = color;
                            pq.push({d + 1, -color, nr, nc});
                        }
                    }
                }
            }
        }

        return ans;
    }
};
