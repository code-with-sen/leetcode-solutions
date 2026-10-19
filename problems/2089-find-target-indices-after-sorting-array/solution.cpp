// 2089. Find Target Indices After Sorting Array [Easy]
// https://leetcode.com/problems/find-target-indices-after-sorting-array/
// Language: C++ | Runtime: 0 ms | Memory: 15.2 MB

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cntLess = 0, cntGr = 0;
        for(auto it : nums){
            if(it < target){
                cntLess++;
            }else if(it > target){
                cntGr++;
            }
        }
        vector<int> sol;
        int n = nums.size() - cntGr - cntLess;
        for(int i = 0; i < n; i++){
            sol.push_back(i + cntLess);
        }
        return sol;
    }
};
