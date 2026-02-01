// 217. Contains Duplicate [Easy]
// https://leetcode.com/problems/contains-duplicate/
// Language: C++ | Runtime: 47 ms | Memory: 90.9 MB

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen; // set contains only unique elements
        for(int num : nums){
            if(seen.contains(num)) return true; // agr hai to true
            seen.insert(num);  // nhi hai to store kro box mei 
        }

        return false;  // sara unique hai to false bolo 
    }
};
