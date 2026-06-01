// 2144. Minimum Cost of Buying Candies With Discount [Easy]
// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
// Language: C++ | Runtime: 0 ms | Memory: 14.1 MB

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int total =0;

        for(int i=cost.size()-1;i>=0;i-=3){
            total += cost[i];
            if(i-1>=0) total+=cost[i-1];
        }

        return total;
    }
};
