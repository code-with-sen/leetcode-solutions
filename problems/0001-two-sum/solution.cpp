// 1. Two Sum [Easy]
// https://leetcode.com/problems/two-sum/
// Language: C++ | Runtime: 0 ms | Memory: 14.9 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // make a dairy 
        for(int i = 0 ; i < nums.size() ; i++){
            int need =  target - nums[i]; // what i need 

            if(mp.find(need) != mp.end()){  // i got this 
                return{mp[need], i};
            }

            mp[nums[i]] = i;  // storing the dairy 
        }

        return {}; // no chance to find in the given array 
    }
};
