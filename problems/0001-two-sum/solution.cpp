// 1. Two Sum [Easy]
// https://leetcode.com/problems/two-sum/
// Language: C++ | Runtime: 3 ms | Memory: 14.7 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i = 0 ; i < nums.size();i++){
            int check = target - nums[i];
            if(hash.find(check) != hash.end()){
                return{hash[check],i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
