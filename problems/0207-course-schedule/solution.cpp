// 207. Course Schedule [Medium]
// https://leetcode.com/problems/course-schedule/
// Language: C++ | Runtime: 11 ms | Memory: 19 MB

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // Build the graph and compute indegrees
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        // Add courses with 0 indegree (no prerequisites)
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            for (int next : adj[course]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return count == numCourses;  // All courses can be finished if no cycles
    }
};
