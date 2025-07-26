// 228. Summary Ranges [Easy]
// https://leetcode.com/problems/summary-ranges/
// Language: C++ | Runtime: 0 ms | Memory: 9.2 MB

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result ;
        int n = nums.size();
        int i = 0;
        while( i < n ){
            int start = i ;
            while(i + 1 < n && nums[i+1] == nums[i] + 1){
                i++;
            }
            if(start == i )
                result.push_back(to_string(nums[start]));
             else
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
                i++;   
        }

        return result ;
    }
};
