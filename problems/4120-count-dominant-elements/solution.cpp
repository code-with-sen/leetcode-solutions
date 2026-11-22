// 4120. Count Dominant Elements [Easy]
// https://leetcode.com/problems/count-dominant-elements/
// Language: C++ | Runtime: 1 ms | Memory: 30.7 MB

class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        if (n == 1) return 1;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (nums[i] >= nums[i + 1]) count++;
            }
            else if (i == n - 1) {
                if (nums[i] >= nums[i - 1]) count++;
            }
            else {
                double avg = (nums[i - 1] + nums[i + 1]) / 2.0;

                if (nums[i] >= avg) count++;
            }
        }

        return count;
    }
};
