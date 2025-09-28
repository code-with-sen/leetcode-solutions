// 976. Largest Perimeter Triangle [Easy]
// https://leetcode.com/problems/largest-perimeter-triangle/
// Language: C++ | Runtime: 6 ms | Memory: 25.5 MB


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>()); // sort descending
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i+1] + nums[i+2] > nums[i]) {
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        return 0;
    }
};
