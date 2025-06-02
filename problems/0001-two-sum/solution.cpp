// 1. Two Sum [Easy]
// https://leetcode.com/problems/two-sum/
// Language: C++ | Runtime: 4 ms | Memory: 15 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
          unordered_map<int,int> hash;
        int n = nums.size();
        for (int i= 0 ; i<n;i++){
            int com = target - nums[i];
            if(hash.find(com) != hash.end() ){
                return{hash[com],i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
