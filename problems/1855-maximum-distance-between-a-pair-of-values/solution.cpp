// 1855. Maximum Distance Between a Pair of Values [Medium]
// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
// Language: C++ | Runtime: 0 ms | Memory: 102.4 MB

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int ans = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                ans = max(ans, j - i);
                j++;
            }else{
                i++;
                if(i > j) j = i;
            }
        }

        return ans;
    }
};
