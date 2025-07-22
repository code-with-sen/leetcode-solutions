// 2149. Rearrange Array Elements by Sign [Medium]
// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Language: C++ | Runtime: 1 ms | Memory: 128.3 MB

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0 , neg = 1;
        vector<int> ans(n);

        for(int num : nums){
            if(num >= 0){
                ans[pos] = num;
                pos +=2;
            }else{
                ans[neg] = num;
                neg += 2;
            }
        }
        return ans;
    }
};
