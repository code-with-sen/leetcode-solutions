// 3074. Apple Redistribution into Boxes [Easy]
// https://leetcode.com/problems/apple-redistribution-into-boxes/
// Language: C++ | Runtime: 3 ms | Memory: 34 MB

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // Sort the capacity array in descending order to use boxes with largest capacity first
        sort(capacity.rbegin(), capacity.rend());
      
        // Calculate the total number of apples that need to be stored
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
      
        // Greedily select boxes starting from the largest capacity
        for (int boxCount = 1; ; ++boxCount) {
            // Subtract the capacity of the current box from remaining apples
            totalApples -= capacity[boxCount - 1];
          
            // If all apples can be stored, return the number of boxes used
            if (totalApples <= 0) {
                return boxCount;
            }
        }
    }
};
