// 66. Plus One [Easy]
// https://leetcode.com/problems/plus-one/
// Language: C++ | Runtime: 0 ms | Memory: 11.6 MB

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Iterate through digits from right to left (least significant to most significant)
        for (int i = digits.size() - 1; i >= 0; --i) {
            // Add 1 to the current digit
            ++digits[i];

            digits[i] %= 10;
          
            if (digits[i] != 0) {
                return digits;
            }
          
        }
              digits.insert(digits.begin(), 1);
      
        return digits;
    }
};
