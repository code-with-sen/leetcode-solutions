// 679. 24 Game [Hard]
// https://leetcode.com/problems/24-game/
// Language: C++ | Runtime: 99 ms | Memory: 38.5 MB

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int x : cards) nums.push_back((double)x);
        return solve(nums);
    }
    
    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - 24) < 1e-6;
        }
        
        // Try all pairs
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }
                
                // Try all operations
                for (double num : compute(nums[i], nums[j])) {
                    next.push_back(num);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
    
    vector<double> compute(double a, double b) {
        vector<double> results;
        results.push_back(a + b);
        results.push_back(a - b);
        results.push_back(b - a);
        results.push_back(a * b);
        if (fabs(b) > 1e-6) results.push_back(a / b);
        if (fabs(a) > 1e-6) results.push_back(b / a);
        return results;
    }
};
