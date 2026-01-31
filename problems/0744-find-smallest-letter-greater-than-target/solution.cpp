// 744. Find Smallest Letter Greater Than Target [Easy]
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Language: C++ | Runtime: 0 ms | Memory: 19.7 MB

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int left = 0;
        int right = n - 1;
        int firstTrueIndex = -1;

        // Binary search to find the first index where letters[mid] > target
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Feasible condition: is this character greater than target?
            if (letters[mid] > target) {
                firstTrueIndex = mid;  // Record potential answer
                right = mid - 1;  // Search left for smaller valid index
            } else {
                left = mid + 1;  // Search right
            }
        }

        // Handle wrap-around: if no character is greater, return first character
        if (firstTrueIndex == -1) {
            return letters[0];
        }
        return letters[firstTrueIndex];
    }
};
