// 1. Two Sum [Easy]
// https://leetcode.com/problems/two-sum/
// Language: C++ | Runtime: 4 ms | Memory: 15 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int > hash;
        for(int i = 0 ; i < nums.size(); i++){
            int complement = target - nums[i];
             if(hash.find(complement) != hash.end()){
                return {hash[complement], i};
          }

          hash[nums[i]] = i ;
        }

        return {};
    }
};
