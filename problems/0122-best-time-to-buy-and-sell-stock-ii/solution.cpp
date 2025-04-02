// 122. Best Time to Buy and Sell Stock II [Medium]
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Language: C++ | Runtime: 0 ms | Memory: 17.1 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        for(int i = 1;i<n;i++){
            if(prices[i]>prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};
