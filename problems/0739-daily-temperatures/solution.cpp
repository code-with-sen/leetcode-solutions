// 739. Daily Temperatures [Medium]
// https://leetcode.com/problems/daily-temperatures/
// Language: C++ | Runtime: 16 ms | Memory: 107.3 MB

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();  // no of days in temps
        vector<int> ans(n , 0); // n size ka hai 0 value h sbka
        stack<int> st;    // stack bana liya 

        for(int i = 0 ; i < n ; i++){  // 0 index se last index tk 
            while(!st.empty() && temps[i] > temps[st.top()]){
                int lastDay = st.top(); // index hai mera 
                st.pop();
                ans[lastDay] = i - lastDay; // ans ka index mei =>
            }

            st.push(i); // pushing the index
        }

        return ans;  // pura ans vector 
    }
};
