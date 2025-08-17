// 1752. Check if Array Is Sorted and Rotated [Easy]
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Language: C++ | Runtime: 0 ms | Memory: 11.2 MB

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // Count the number of places where order breaks
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i+1) % n]) {
                count++;
            }
        }

        // For a sorted & rotated array, order can break at most once
        return count <= 1;
    }
};
