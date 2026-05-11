// 739. Daily Temperatures [Medium]
// https://leetcode.com/problems/daily-temperatures/
// Language: C++ | Runtime: 24 ms | Memory: 107.3 MB

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size(); // no of days 
        stack<int> st;
        vector<int> ans(n,0); // n size ka hai 0 hai sbmei.

        for(int i = 0 ; i < n; i++){
            while(!st.empty() && temp[i] > temp[st.top()]){
                int prev = st.top(); // index mei use hoga
                st.pop();
                ans[prev] = i - prev; // ans ka index mei result
            }

            st.push(i); // only index 
        }

        return ans; // vector form mei hai 
    }
};
