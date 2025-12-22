// 960. Delete Columns to Make Sorted III [Hard]
// https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
// Language: C++ | Runtime: 0 ms | Memory: 13.5 MB

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // Get the number of columns (length of first string)
        int numColumns = strs[0].size();
      
        // dp[i] represents the maximum length of increasing subsequence ending at column i
        // Initialize all positions with 1 (each column alone forms a valid subsequence of length 1)
        vector<int> dp(numColumns, 1);
      
        // Build up the dp array by checking each column
        for (int currentCol = 1; currentCol < numColumns; ++currentCol) {
            // Check all previous columns to see if we can extend their subsequences
            for (int prevCol = 0; prevCol < currentCol; ++prevCol) {
                // Check if all strings maintain non-decreasing order from prevCol to currentCol
                bool canExtend = true;
                for (const string& str : strs) {
                    if (str[prevCol] > str[currentCol]) {
                        canExtend = false;
                        break;
                    }
                }
              
                // If we can extend the subsequence from prevCol to currentCol
                if (canExtend) {
                    dp[currentCol] = max(dp[currentCol], dp[prevCol] + 1);
                }
            }
        }
      
        // Find the maximum length of valid column subsequence
        int maxValidColumns = *max_element(dp.begin(), dp.end());
      
        // Minimum deletions = total columns - maximum valid columns we can keep
        return numColumns - maxValidColumns;
    }
};
