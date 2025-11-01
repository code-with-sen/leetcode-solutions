// 1. Two Sum [Easy]
// https://leetcode.com/problems/two-sum/
// Language: C++ | Runtime: 2 ms | Memory: 14.9 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // chocolates ka note banao
        
        for(int i = 0 ; i < nums.size(); i++){ // suru se search karo 
            int need = target - nums[i]; // kya hai aur kitna chaiye 

            if(mp.find(need) != mp.end()){ // hai mil gya 
                return{mp[need],i};  // dusra wla aur phle wla return kr diya 
            }

            mp[nums[i]] = i; // nhi mila bss store kr rha hu aage ke liye 
        }

        return{}; // end tk nhi mila empty return kr rha hu 
    }
};
