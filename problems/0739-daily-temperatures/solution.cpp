// 739. Daily Temperatures [Medium]
// https://leetcode.com/problems/daily-temperatures/
// Language: C++ | Runtime: 15 ms | Memory: 107.2 MB

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        
        int n = temps.size();
        vector<int> ans(n,0);
        stack<int> st;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && temps[i] > temps[st.top()]){
                int prev = st.top();
                st.pop();
                ans[prev] = i - prev;
            }
            st.push(i); // pushing the index
        }

        return ans;
    }
};
