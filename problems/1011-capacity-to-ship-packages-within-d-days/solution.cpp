// 1011. Capacity To Ship Packages Within D Days [Medium]
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Language: C++ | Runtime: 13 ms | Memory: 35 MB

class Solution {
public:
    bool cancarry(vector<int>&weights , int capacity , int days){
        int currweight = 0 , daycount = 1;
        for(int w : weights){
            if(currweight + w > capacity){
                daycount++;
                currweight = 0;
            }
            currweight += w ;

        }
        return daycount <= days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(), 0);
       
         int ans = high;
        while(low <= high){
             int med = low + (high - low )/2;
            if(cancarry(weights, med, days)){
                ans = med ;
                high = med - 1;
            }else{
                low = med + 1;
            }
        }

        return ans ;
    }
};
