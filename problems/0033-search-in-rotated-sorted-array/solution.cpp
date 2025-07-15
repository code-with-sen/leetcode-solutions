// 33. Search in Rotated Sorted Array [Medium]
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Language: C++ | Runtime: 0 ms | Memory: 15.1 MB

class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int left = 0 ;
        int right = nums.size() -1 ;
        while(left <= right){
            int mid = (left + right)/2;

            if(nums[mid] == tar) return mid;

            if(nums[left] <= nums[mid]){
                if(nums[left] <= tar && tar < nums[mid]){
                    right = mid -1;
                }else{
                    left = mid + 1;
                }
            } else{

            if(nums[mid] < tar && tar <= nums[right]){
            left  = mid +  1;
        }else {
            right  = mid - 1 ;
        }
        }
        }
        return -1;

            
       
    }
};
