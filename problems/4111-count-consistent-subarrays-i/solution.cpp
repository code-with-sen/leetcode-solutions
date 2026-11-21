// 4111. Count Consistent Subarrays I [Easy]
// https://leetcode.com/problems/count-consistent-subarrays-i/
// Language: C++ | Runtime: 1 ms | Memory: 30 MB

class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i, a = ~0, m = 1e9; j < n; ++j)
                ans += ((a &= nums[j]) == (m = min(m, nums[j])));
        return ans;
    }
};
