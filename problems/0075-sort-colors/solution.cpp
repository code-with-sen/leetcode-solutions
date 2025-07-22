// 75. Sort Colors [Medium]
// https://leetcode.com/problems/sort-colors/
// Language: C++ | Runtime: 0 ms | Memory: 11.5 MB

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0 ,med = 0, high = nums.size() -1;

        while(med <= high ){
            if(nums[med]==0){
                swap(nums[low], nums[med]);
                low++;
                med++;
            }else if(nums[med]==1){
                
                    med++;
                }else{
                    swap(nums[med],nums[high]);
                    high--;
                }
            }
        
        
    }
};
