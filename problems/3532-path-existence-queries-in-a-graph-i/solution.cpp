// 3532. Path Existence Queries in a Graph I [Medium]
// https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
// Language: C++ | Runtime: 9 ms | Memory: 224.1 MB

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> cmp(n);

        for (int i = 1; i < n; i++) {
            cmp[i] = cmp[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
        }

        vector<bool> res;

        for (const auto &q : queries) {
            res.push_back(cmp[q[0]] == cmp[q[1]]);
        }

        return res;
    }
};
