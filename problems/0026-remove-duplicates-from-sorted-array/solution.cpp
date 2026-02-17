// 26. Remove Duplicates from Sorted Array [Easy]
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Language: C++ | Runtime: 0 ms | Memory: 22.5 MB

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i -1])
                nums[k++] = nums[i];
        }

        return k;
    }
};
