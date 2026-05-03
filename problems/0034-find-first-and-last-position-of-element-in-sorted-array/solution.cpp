// 34. Find First and Last Position of Element in Sorted Array [Medium]
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Language: C++ | Runtime: 0 ms | Memory: 17.5 MB

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if(nums.empty()) return {-1, -1};

        int low = 0, high = nums.size() - 1, mid;
        int first = -1, last = -1;

        // First element
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // Last element
        low = 0, high = nums.size() - 1;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return {first, last};
    }
};
