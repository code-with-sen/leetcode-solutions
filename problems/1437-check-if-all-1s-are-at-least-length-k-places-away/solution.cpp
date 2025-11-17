// 1437. Check If All 1's Are at Least Length K Places Away [Easy]
// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
// Language: C++ | Runtime: 0 ms | Memory: 61.4 MB

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1e9; // a very small number so first 1 is always OK
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == 1) {
                if (i - last <= k) return false; // not enough zeros between ones
                last = i;
            }
        }
        return true;
    }
};
