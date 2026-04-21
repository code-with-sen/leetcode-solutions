// 85. Maximal Rectangle [Hard]
// https://leetcode.com/problems/maximal-rectangle/
// Language: C++ | Runtime: 3 ms | Memory: 19.1 MB

class Solution {
public:

// LRH => Largest Rectangle in Histogram concept 
    int largestRectangleArea(vector<int>& height){
        int n = height.size();
        stack<int> st;
        int maxArea = 0 ;

        for(int i = 0 ; i <= n ; i++){
            int curr = (i == n) ? 0 : height[i];
            while(!st.empty() && curr < height[st.top()]){
                int h = height[st.top()];
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
       if(matrix.empty()) return 0;
       int n = matrix[0].size();
       vector<int> height(n,0);
       int maxArea = 0;

       for(auto& row : matrix){
        for(int i = 0 ; i < n; i++){
            if(row[i] == '1')
                height[i] += 1;
            else
                height[i] = 0;
            

        }
            maxArea = max(maxArea, largestRectangleArea(height));
       }
      
      return maxArea;
    }
};
