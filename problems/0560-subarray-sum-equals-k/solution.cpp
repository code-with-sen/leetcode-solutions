// 560. Subarray Sum Equals K [Medium]
// https://leetcode.com/problems/subarray-sum-equals-k/
// Language: C++ | Runtime: 32 ms | Memory: 45.4 MB

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixsum;
        prefixsum[0] = 1;

        int count = 0;
        int currsum = 0;

        for(int i = 0 ; i < nums.size();i++){
            currsum += nums[i];

            if(prefixsum.find(currsum - k) != prefixsum.end()){
                count += prefixsum[currsum - k];
            }

            prefixsum[currsum]++;
        }

        return count;
        
    }
};
