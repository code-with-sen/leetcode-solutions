// 2913. Subarrays Distinct Element Sum of Squares I [Easy]
// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
// Language: C++ | Runtime: 40 ms | Memory: 36.4 MB

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            set<int> st;
            for(int j=i; j<n; j++){
                st.insert(nums[j]);
                ans += st.size()*st.size();
            }
        }
        return ans;
    }
};
