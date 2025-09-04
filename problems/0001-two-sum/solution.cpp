// 1. Two Sum [Easy]
// https://leetcode.com/problems/two-sum/
// Language: C++ | Runtime: 0 ms | Memory: 15 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int n = nums.size();
        for(int i = 0 ; i < n;i++){
            int check = target - nums[i];
            if(hash.find(check) != hash.end()){
                return{hash[check],i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
