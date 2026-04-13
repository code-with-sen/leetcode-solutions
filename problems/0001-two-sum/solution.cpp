// 1. Two Sum [Easy]
// https://leetcode.com/problems/two-sum/
// Language: C++ | Runtime: 3 ms | Memory: 14.8 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>container;

        for(int i = 0 ; i < nums.size(); i++){
            int need = target - nums[i];

            if(container.find(need) != container.end()){
                return{container[need], i};
            }

            container[nums[i]] = i;
        }
        return {};
    }
};
