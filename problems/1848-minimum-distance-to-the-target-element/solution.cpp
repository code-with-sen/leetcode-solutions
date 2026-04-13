// 1848. Minimum Distance to the Target Element [Easy]
// https://leetcode.com/problems/minimum-distance-to-the-target-element/
// Language: C++ | Runtime: 0 ms | Memory: 13.3 MB

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int result = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
                result = min(result,abs(i-start));
        }
        return result;
    }
};
