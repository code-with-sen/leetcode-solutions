// 1. Two Sum [Easy]
// https://leetcode.com/problems/two-sum/
// Language: C++ | Runtime: 4 ms | Memory: 14.8 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for(int i = 0 ; i < nums.size(); i++){
            int need = target - nums[i];
            if(mpp.find(need) != mpp.end()){
                return {mpp[need], i};
            }

            mpp[nums[i]] = i;
        }

        return {};
    }
};
