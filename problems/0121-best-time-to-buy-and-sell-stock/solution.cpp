// 121. Best Time to Buy and Sell Stock [Easy]
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Language: C++ | Runtime: 0 ms | Memory: 97.6 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxprofit = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            int cost = prices[i] - mini;
            maxprofit = max(maxprofit,cost);
            mini = min(mini,prices[i]);
        }

        return maxprofit;
    }
};
