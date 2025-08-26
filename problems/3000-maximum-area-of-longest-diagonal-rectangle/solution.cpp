// 3000. Maximum Area of Longest Diagonal Rectangle [Easy]
// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/
// Language: C++ | Runtime: 0 ms | Memory: 29.4 MB

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0, mx = 0;
        for (auto& d : dimensions) {
            int l = d[0], w = d[1];
            int diag2 = l * l + w * w;
            int area = l * w;
            if (diag2 > mx) {
                mx = diag2;
                ans = area;
            } else if (diag2 == mx) {
                ans = max(ans, area);
            }
        }
        return ans;
    }
};
