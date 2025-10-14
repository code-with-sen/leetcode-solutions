// 3349. Adjacent Increasing Subarrays Detection I [Easy]
// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/
// Language: C++ | Runtime: 10 ms | Memory: 40.3 MB

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cur = 1;        // length of current strictly increasing segment
        int prev = 0;       // length of previous strictly increasing segment
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {
                // segment ended
                // check the condition
                if (cur / 2 >= k || min(prev, cur) >= k) return true;
                
                prev = cur;
                cur = 1;
            }
        }
        // check at the end also
        if (cur / 2 >= k || min(prev, cur) >= k) return true;
        
        return false;
    }
};
