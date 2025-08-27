// 3459. Length of Longest V-Shaped Diagonal Segment [Hard]
// https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/
// Language: C++ | Runtime: 2796 ms | Memory: 588.9 MB

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int,int> nxt = {{1,2},{2,0},{0,2}};
        static constexpr int dirs[4][2] = {{1,1},{1,-1},{-1,-1},{-1,1}};
        // dp cache: i, j, dir (0-3), turned (0/1)
        vector dp(m, vector(n, vector(4, vector<int>(2, -1))));
        
        function<int(int,int,int,int)> dfs = [&](int i, int j, int d, int turned) {
            int& res = dp[i][j][d][turned];
            if (res != -1) return res;
            res = 1;
            int ni = i + dirs[d][0], nj = j + dirs[d][1];
            int target = nxt[grid[i][j]];
            
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == target) {
                res = 1 + dfs(ni, nj, d, turned);
            }
            if (!turned) {
                int nd = (d + 1) % 4;
                int ti = i + dirs[nd][0], tj = j + dirs[nd][1];
                if (ti >= 0 && ti < m && tj >= 0 && tj < n && grid[ti][tj] == target) {
                    res = max(res, 1 + dfs(ti, tj, nd, 1));
                }
            }
            return res;
        };
        
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    for (int d = 0; d < 4; ++d)
                        ans = max(ans, dfs(i, j, d, 0));
        return ans;
    }
};
