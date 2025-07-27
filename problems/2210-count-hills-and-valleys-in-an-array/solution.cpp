// 2210. Count Hills and Valleys in an Array [Easy]
// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
// Language: C++ | Runtime: 0 ms | Memory: 12.1 MB

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;

        // Remove consecutive duplicates
        vector<int> filtered;
        filtered.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                filtered.push_back(nums[i]);
            }
        }

        // Now count hills and valleys
        for (int i = 1; i < filtered.size() - 1; i++) {
            if ((filtered[i] > filtered[i - 1] && filtered[i] > filtered[i + 1]) ||
                (filtered[i] < filtered[i - 1] && filtered[i] < filtered[i + 1])) {
                count++;
            }
        }

        return count;
    }
};
