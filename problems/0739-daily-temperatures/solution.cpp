// 739. Daily Temperatures [Medium]
// https://leetcode.com/problems/daily-temperatures/
// Language: C++ | Runtime: 23 ms | Memory: 107.4 MB

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && temp[i] > temp[st.top()]){
                int prev = st.top();
                st.pop();
                ans[prev] = i - prev;
            }
            st.push(i);
        }
        return ans;
    }
};
