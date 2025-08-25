// 493. Reverse Pairs [Hard]
// https://leetcode.com/problems/reverse-pairs/
// Language: C++ | Runtime: 178 ms | Memory: 99.2 MB

class Solution {
public:
    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);

        // Count reverse pairs
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long)nums[i] > 2LL * nums[j]) j++;
            count += (j - (mid + 1));
        }

        // Merge two sorted halves
        inplace_merge(nums.begin() + low, nums.begin() + mid + 1, nums.begin() + high + 1);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
