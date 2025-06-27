// 1. Two Sum [Easy]
// https://leetcode.com/problems/two-sum/
// Language: C++ | Runtime: 1 ms | Memory: 14.8 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int >map;
        for(int i = 0 ; i<nums.size();i++){
            int com = target - nums[i];
            if(map.find(com) != map.end()){
                return{map[com],i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
