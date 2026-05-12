// 1665. Minimum Initial Energy to Finish Tasks [Hard]
// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
// Language: C++ | Runtime: 28 ms | Memory: 97.4 MB

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [](vector<int>& a, vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]);
             });

        int curr = 0;
        int ans  = 0;
        for (auto& task : tasks) {
            int actual  = task[0];
            int minimum = task[1];
            if (curr < minimum) {
                ans  += (minimum - curr);
                curr  = minimum;
            }
            curr -= actual;
        }
        return ans;
    }
};
