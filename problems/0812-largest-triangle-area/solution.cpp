// 812. Largest Triangle Area [Easy]
// https://leetcode.com/problems/largest-triangle-area/
// Language: C++ | Runtime: 0 ms | Memory: 10.3 MB



class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0.0;

        auto area = [&](vector<int>& a, vector<int>& b, vector<int>& c) {
            return fabs(a[0] * (b[1] - c[1]) +
                        b[0] * (c[1] - a[1]) +
                        c[0] * (a[1] - b[1])) / 2.0;
        };

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    maxArea = max(maxArea, area(points[i], points[j], points[k]));
                }
            }
        }

        return maxArea;
    }
};
