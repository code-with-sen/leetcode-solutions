// 217. Contains Duplicate [Easy]
// https://leetcode.com/problems/contains-duplicate/
// Language: C++ | Runtime: 43 ms | Memory: 90.7 MB

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num : nums){
            if(seen.contains(num))  return true;
            seen.insert(num);
        }

        return false;
    }
};
