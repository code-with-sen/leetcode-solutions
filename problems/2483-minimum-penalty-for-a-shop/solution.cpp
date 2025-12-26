// 2483. Minimum Penalty for a Shop [Medium]
// https://leetcode.com/problems/minimum-penalty-for-a-shop/
// Language: C++ | Runtime: 2 ms | Memory: 17.6 MB

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
      
        // prefixSum[i] stores the count of 'Y' (customers) from index 0 to i-1
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + (customers[i] == 'Y');
        }
      
        int bestHour = 0;
        int minCost = INT_MAX;
      
        // Try each possible closing hour from 0 to n
        for (int closingHour = 0; closingHour <= n; ++closingHour) {
            // Calculate penalty for closing at this hour:
            // - Hours before closing with 'N': closingHour - prefixSum[closingHour]
            // - Hours after closing with 'Y': prefixSum[n] - prefixSum[closingHour]
            int noCustomerPenalty = closingHour - prefixSum[closingHour];
            int customerPenalty = prefixSum[n] - prefixSum[closingHour];
            int totalCost = noCustomerPenalty + customerPenalty;
          
            // Update the best closing hour if we found a lower cost
            if (totalCost < minCost) {
                bestHour = closingHour;
                minCost = totalCost;
            }
        }
      
        return bestHour;
    }
};
