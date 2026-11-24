// 3411. Maximum Subarray With Equal Products [Easy]
// https://leetcode.com/problems/maximum-subarray-with-equal-products/
// Language: C++ | Runtime: 0 ms | Memory: 28 MB

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int best = 2, left = 0, product = 1;
        for (int right = 0; right < ssize(nums); ++right) {
            int x = nums[right];
            while (gcd(product, x) > 1)
                product /= nums[left++];
            product *= x;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
