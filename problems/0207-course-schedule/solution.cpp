// 207. Course Schedule [Medium]
// https://leetcode.com/problems/course-schedule/
// Language: C++ | Runtime: 4 ms | Memory: 19.3 MB

class Solution {
public:
    bool canFinish(int numcourse, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numcourse);
        vector<int> indegree(numcourse,0);

        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int>q;
        for(int i = 0 ; i < numcourse ; i++){
            if(indegree[i] == 0 ) q.push(i);
        }

        int count = 0 ;
        while(!q.empty()){
            int node = q.front();q.pop();
            count++;


        for(int neighbor : adj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0 ) q.push(neighbor);
        }

        }

        return count == numcourse;
    }
};
