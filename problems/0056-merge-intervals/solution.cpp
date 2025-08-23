// 56. Merge Intervals [Medium]
// https://leetcode.com/problems/merge-intervals/
// Language: C++ | Runtime: 3 ms | Memory: 23.6 MB

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i = 0 ; i < n ; i++){
             if(ans.empty() || intervals[i][0] > ans.back()[1]){
            ans.push_back(intervals[i]);
             }else{
                 ans.back()[1] = max(ans.back()[1],intervals[i][1]);
          }
        }
        return ans;
    }
};
