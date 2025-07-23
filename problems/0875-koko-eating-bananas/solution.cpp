// 875. Koko Eating Bananas [Medium]
// https://leetcode.com/problems/koko-eating-bananas/
// Language: C++ | Runtime: 7 ms | Memory: 22.8 MB

class Solution {
public:

    bool Caneatall(vector<int>& piles , int h , int k ){
    long long hours = 0;
    for(int bananas : piles){
        hours += (bananas + k - 1)/ k ;
    } 

    return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = *max_element(piles.begin(),piles.end());
        int ans = high;
       
        while( low <= high){
            int med = low + (high - low )/2;
            if(Caneatall(piles, h , med )){
                ans = med ;
                high = med -1 ;
            }else{
                low = med + 1;
            }
        }
        return ans ;
        
    }
};
