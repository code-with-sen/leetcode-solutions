// 1200. Minimum Absolute Difference [Easy]
// https://leetcode.com/problems/minimum-absolute-difference/
// Language: C++ | Runtime: 18 ms | Memory: 36.7 MB

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Sort the array to easily find consecutive differences
        sort(arr.begin(), arr.end());
      
        // Initialize minimum difference to a large value (2^30)
        int minDifference = 1 << 30;
        int arraySize = arr.size();
      
        // First pass: find the minimum absolute difference between consecutive elements
        for (int i = 0; i < arraySize - 1; ++i) {
            int currentDifference = arr[i + 1] - arr[i];
            minDifference = min(minDifference, currentDifference);
        }
      
        // Store all pairs with the minimum absolute difference
        vector<vector<int>> result;
      
        // Second pass: collect all pairs that have the minimum difference
        for (int i = 0; i < arraySize - 1; ++i) {
            if (arr[i + 1] - arr[i] == minDifference) {
                // Add the pair to result (already in ascending order due to sorting)
                result.push_back({arr[i], arr[i + 1]});
            }
        }
      
        return result;
    }
};
