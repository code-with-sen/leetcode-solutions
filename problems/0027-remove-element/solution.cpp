// 27. Remove Element [Easy]
// https://leetcode.com/problems/remove-element/
// Language: C++ | Runtime: 0 ms | Memory: 11.8 MB

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0 ;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] != val)
                nums[count++] = nums[i];
        }
        return count;
    }
};
