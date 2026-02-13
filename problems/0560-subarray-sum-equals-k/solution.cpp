// 560. Subarray Sum Equals K [Medium]
// https://leetcode.com/problems/subarray-sum-equals-k/
// Language: C++ | Runtime: 71 ms | Memory: 53.9 MB

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mpp;
        mpp[0] = 1;
        int presum = 0 , count = 0;
        for(int i = 0 ; i < nums.size(); i++){
            presum += nums[i];
            int remove = presum - k;
            count += mpp[remove];
            mpp[presum] += 1;
        }

        return count;
    }
};
