// 611. Valid Triangle Number [Medium]
// https://leetcode.com/problems/valid-triangle-number/
// Language: C++ | Runtime: 36 ms | Memory: 16.7 MB

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // sort array
        int count = 0;

        // Fix the largest side nums[k]
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // All values from i..j-1 with nums[j] form valid triangles
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};
