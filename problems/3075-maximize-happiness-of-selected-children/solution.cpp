// 3075. Maximize Happiness of Selected Children [Medium]
// https://leetcode.com/problems/maximize-happiness-of-selected-children/
// Language: C++ | Runtime: 205 ms | Memory: 110.2 MB

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Sort the happiness array in descending order to prioritize selecting children with higher happiness
        sort(happiness.rbegin(), happiness.rend());
      
        // Initialize the total happiness sum
        long long totalHappiness = 0;
      
        // Select k children with the highest happiness values
        for (int i = 0; i < k; ++i) {
            // Calculate adjusted happiness after i children have already been selected
            // Each previously selected child reduces current child's happiness by 1
            int adjustedHappiness = happiness[i] - i;
          
            // Add the adjusted happiness to total (minimum 0 if happiness becomes negative)
            totalHappiness += max(adjustedHappiness, 0);
        }
      
        return totalHappiness;
    }
};
