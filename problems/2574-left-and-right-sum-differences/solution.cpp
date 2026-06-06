// 2574. Left and Right Sum Differences [Easy]
// https://leetcode.com/problems/left-and-right-sum-differences/
// Language: C++ | Runtime: 0 ms | Memory: 14.9 MB

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int right_sum=0;

        for(int i=0;i<nums.size();i++){
            right_sum+=nums[i];
        }

        int left_sum=0;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            right_sum -= nums[i];
            result.push_back(abs(left_sum-right_sum));
            left_sum += nums[i];
        }

        return result;
    }
};
