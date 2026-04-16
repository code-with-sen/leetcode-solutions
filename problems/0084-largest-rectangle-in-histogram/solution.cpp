// 84. Largest Rectangle in Histogram [Hard]
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Language: C++ | Runtime: 19 ms | Memory: 81.4 MB

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
       stack<int>st;
       int maxArea = 0;
       int n = height.size();

      for(int i = 0; i <= n ; i++){
        int currentHeight = (i == n) ? 0 : height[i];

        while(!st.empty() && height[st.top()] > currentHeight){
            int h = height[st.top()];
            st.pop();

            int width;
            if(st.empty()){
                width = i;
            }else{
                width = i - st.top() - 1;
            }

            maxArea = max(maxArea, h * width);
        }
           
            st.push(i);
        }

        return maxArea;
    }
};
