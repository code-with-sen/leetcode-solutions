// 560. Subarray Sum Equals K [Medium]
// https://leetcode.com/problems/subarray-sum-equals-k/
// Language: C++ | Runtime: 39 ms | Memory: 45.3 MB

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> prefixsum;
        prefixsum[0] = 1;
        int count = 0 ;
        int currsum = 0 ;
        
        for (int num : nums){
            currsum += num;

            if(prefixsum.find(currsum - k ) != prefixsum.end()){
                count += prefixsum[currsum - k ];
            }

            prefixsum[currsum]++;
        }
        return count ;
    }
};
