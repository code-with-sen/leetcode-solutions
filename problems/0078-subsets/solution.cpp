// 78. Subsets [Medium]
// https://leetcode.com/problems/subsets/
// Language: C++ | Runtime: 0 ms | Memory: 9.9 MB

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> resultset;
        vector<int> tempset;
        backtrack(resultset,tempset,nums,0);
        return resultset;
    }
    private:
        void backtrack(vector<vector<int>>& resultset,vector<int>& tempset,vector<int>& nums,int start){
            resultset.push_back(tempset);
            for(int i = start;i<nums.size();i++){
                tempset.push_back(nums[i]);
                backtrack(resultset,tempset,nums,i+1);
                tempset.pop_back();
            }
        }
};
