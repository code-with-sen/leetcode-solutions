// 33. Search in Rotated Sorted Array [Medium]
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Language: C++ | Runtime: 0 ms | Memory: 15.2 MB

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            // ✅ Found target
            if (nums[mid] == target) return mid;

            // \U0001f9ed Left side is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // target lies in left half
                } else {
                    left = mid + 1;   // target in right half
                }
            }
            // \U0001f504 Right side is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;   // target in right half
                } else {
                    right = mid - 1;  // target in left half
                }
            }
        }

        return -1; // ❌ Not found
    }
};
