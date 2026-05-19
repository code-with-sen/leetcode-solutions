// 2540. Minimum Common Value [Easy]
// https://leetcode.com/problems/minimum-common-value/
// Language: C++ | Runtime: 0 ms | Memory: 54.6 MB

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int result=-1;
        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                result=nums1[i];
                break;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return result;
    }
};
