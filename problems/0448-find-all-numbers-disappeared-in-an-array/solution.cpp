// 448. Find All Numbers Disappeared in an Array [Easy]
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Language: C++ | Runtime: 4 ms | Memory: 53 MB

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0 ; i < nums.size(); i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0)
                nums[index] = -nums[index];
        }

        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};
