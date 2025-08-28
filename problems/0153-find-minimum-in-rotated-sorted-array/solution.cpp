// 153. Find Minimum in Rotated Sorted Array [Medium]
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Language: C++ | Runtime: 0 ms | Memory: 14.2 MB

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If the current segment is sorted, nums[low] is the minimum in this range
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break; // No need to search further
            }

            // Left part is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right part is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
