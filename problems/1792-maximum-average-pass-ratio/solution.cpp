// 1792. Maximum Average Pass Ratio [Medium]
// https://leetcode.com/problems/maximum-average-pass-ratio/
// Language: C++ | Runtime: 813 ms | Memory: 93.5 MB

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Custom comparator for max heap
        auto gain = [](const pair<int,int>& c) {
            return (double)(c.first + 1) / (c.second + 1) - (double)c.first / c.second;
        };

        // Max heap storing {pass, total} based on maximum gain
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
                       function<bool(pair<int,int>&, pair<int,int>&)>> pq(
            [&](pair<int,int>& a, pair<int,int>& b){
                return gain(a) < gain(b);
            }
        );

        // Push all classes
        for(auto &c : classes) pq.push({c[0], c[1]});

        // Allocate extra students
        while(extraStudents--) {
            auto top = pq.top();
            pq.pop();
            top.first++;   // add student passed
            top.second++;  // total students increase
            pq.push(top);
        }

        // Calculate final average
        double total = 0.0;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            total += (double)top.first / top.second;
        }

        return total / classes.size();
    }
};
