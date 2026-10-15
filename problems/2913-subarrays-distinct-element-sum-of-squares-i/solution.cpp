// 2913. Subarrays Distinct Element Sum of Squares I [Easy]
// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
// Language: C++ | Runtime: 39 ms | Memory: 36.6 MB

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int res = 0 ;

        for(int i = 0 ; i < n ; i++){
          unordered_set<int> st;

            for(int j = i ; j < n ; j++){
                st.insert(nums[j]);     // insert karna 
                int m = st.size();
                
                res += m * m;   // multiple by itself 
            }
        }

        return res ;    // result to be printed 
        
    }
};
