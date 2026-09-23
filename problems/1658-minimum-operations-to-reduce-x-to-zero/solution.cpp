// 1658. Minimum Operations to Reduce X to Zero [Medium]
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// Language: C++ | Runtime: 4 ms | Memory: 102.4 MB

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        if(target < 0) return -1;
        if(target == 0) return n;

        int left = 0;
        int sum = 0;
        int longest = -1;

        for(int right = 0; right < n; right++){
            sum += nums[right];
            while(left <= right && sum > target){
                sum -= nums[left++];
            }
            if(sum == target){
                longest = max(longest, right - left + 1);
            }
        }

        return longest == -1 ? -1 : n - longest;
    }
};
