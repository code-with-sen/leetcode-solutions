// 85. Maximal Rectangle [Hard]
// https://leetcode.com/problems/maximal-rectangle/
// Language: C++ | Runtime: 3 ms | Memory: 19.4 MB

class Solution {
public:

// LRH => Largest Rectangle in Histogram concept 

   int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : heights[i];

            while (!st.empty() && curr < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

              
                int width = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }

// binary area starts from here 

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (auto& row : matrix) {
            for (int i = 0; i < n; i++) {
                if (row[i] == '1')
                    heights[i] += 1;
                else
                    heights[i] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
