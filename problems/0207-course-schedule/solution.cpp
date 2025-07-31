// 207. Course Schedule [Medium]
// https://leetcode.com/problems/course-schedule/
// Language: C++ | Runtime: 12 ms | Memory: 19.3 MB

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj , vector<int>& visited ,
    vector<int>& pathvisited){

        visited[node] = 1 ;
        pathvisited[node] = 1;

        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor , adj , visited , pathvisited))
                    return true;
                
            }else if(pathvisited[neighbor]){
                
                    return true;
            }

        }
                
            pathvisited[node] = 0 ;
            return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses,0);
        vector<int> pathvisited(numCourses,0);
        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i]){
                if(dfs(i , adj , visited , pathvisited))
                    return false;
            }
        }

        return true;
    }
};
