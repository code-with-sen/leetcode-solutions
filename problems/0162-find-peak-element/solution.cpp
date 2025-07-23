// 162. Find Peak Element [Medium]
// https://leetcode.com/problems/find-peak-element/
// Language: C++ | Runtime: 0 ms | Memory: 12.4 MB

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0 , high = nums.size() - 1;
       
        while(low < high){
             int med = low  + (high - low ) /2;

            if(nums[med] > nums[med+1]){
                high = med;
            }else{
                low = med + 1;
            }
        }
        return low;
    }
};
