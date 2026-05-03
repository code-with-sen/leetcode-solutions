// 35. Search Insert Position [Easy]
// https://leetcode.com/problems/search-insert-position/
// Language: C++ | Runtime: 0 ms | Memory: 13.5 MB

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low = 0 , high = nums.size() -1, mid;
        while(low <= high){
            mid = low + (high - low)/2;

            if(nums[mid] == target){
                return mid;
                // ans = mid;
                // break;
            }else if(nums[mid] < target)
                low = mid + 1;
            else {
            //   ans = mid;
              high = mid - 1;    
        }
      }
        return low;
    }
};
