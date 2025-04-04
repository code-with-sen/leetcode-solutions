// 31. Next Permutation [Medium]
// https://leetcode.com/problems/next-permutation/
// Language: C++ | Runtime: 0 ms | Memory: 15.8 MB

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int na = -1;
        int n = a.size();
        for(int i = n-2;i>=0;i--){
            if(a[i] < a[i+1]){
                na = i ;
                break;
            }
        }
        if(na == -1){
            reverse(a.begin(),a.end());
            return;
        }
        for(int i = n-1;i>na;i--){
            if(a[i]>a[na]){
                swap(a[i],a[na]);
                break;
            }
        }
        reverse(a.begin()+na+1,a.end());
        return;
    }
};
