// 496. Next Greater Element I [Easy]
// https://leetcode.com/problems/next-greater-element-i/
// Language: C++ | Runtime: 4 ms | Memory: 12.9 MB

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;  // TC km krne ke liye (Result fast)
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }

            if(st.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();
        st.push(nums2[i]);  // value push kr rha hu 
        }

        vector<int> res;
        for(int num : nums1){
            res.push_back(mp[num]);
        }

        return res ;


    }
};
