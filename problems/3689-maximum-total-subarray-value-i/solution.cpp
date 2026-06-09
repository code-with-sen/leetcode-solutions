// 3689. Maximum Total Subarray Value I [Medium]
// https://leetcode.com/problems/maximum-total-subarray-value-i/
// Language: C++ | Runtime: 0 ms | Memory: 103.8 MB

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return  (*max_element(nums.begin(),nums.end())  - *min_element(nums.begin(),nums.end()))*1LL*k;
    }
};
