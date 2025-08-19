// 2348. Number of Zero-Filled Subarrays [Medium]
// https://leetcode.com/problems/number-of-zero-filled-subarrays/
// Language: C++ | Runtime: 4 ms | Memory: 111.3 MB

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, streak = 0;
        
        for (int n : nums) {
            if (n == 0) {
                streak++;
                count += streak; 
            } else {
                streak = 0;
            }
        }
        
        return count;
    }
};
