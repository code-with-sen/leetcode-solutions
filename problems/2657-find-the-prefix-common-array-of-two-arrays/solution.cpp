// 2657. Find the Prefix Common Array of Two Arrays [Medium]
// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
// Language: C++ | Runtime: 7 ms | Memory: 88.1 MB

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        int count=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]==B[i]){
                mp[A[i]]+=2;
                count++;
            }
            else{
                mp[A[i]]++;
                mp[B[i]]++;
                if(mp[A[i]]==2){count++;}
                if(mp[B[i]]==2){count++;}
            }
            A[i]=count;
        }
        return A;
    }
};
