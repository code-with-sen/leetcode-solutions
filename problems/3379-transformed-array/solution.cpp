// 3379. Transformed Array [Easy]
// https://leetcode.com/problems/transformed-array/
// Language: C++ | Runtime: 8 ms | Memory: 25.7 MB

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; ++i){
           ans.push_back(nums[(i + nums[i] % n + n) % n]);
        }
        return ans;
    }
};
