// 2011. Final Value of Variable After Performing Operations [Easy]
// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
// Language: C++ | Runtime: 0 ms | Memory: 17.5 MB

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto &op : operations) {
            if (op[1] == '+') x++;
            else x--;
        }
        return x;
    }
};
