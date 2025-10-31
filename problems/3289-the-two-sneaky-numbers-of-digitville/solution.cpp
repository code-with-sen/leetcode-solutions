// 3289. The Two Sneaky Numbers of Digitville [Easy]
// https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
// Language: C++ | Runtime: 0 ms | Memory: 25.7 MB

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        // n <= 100, so we can make a small count array
        vector<int> count(101, 0);
        vector<int> res;
        
        for (int x : nums) {
            count[x]++;
            if (count[x] == 2) {
                res.push_back(x);
                if (res.size() == 2) break;  // stop early
            }
        }
        return res;
    }
};
