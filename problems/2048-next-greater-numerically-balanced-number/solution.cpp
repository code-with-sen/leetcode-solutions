// 2048. Next Greater Numerically Balanced Number [Medium]
// https://leetcode.com/problems/next-greater-numerically-balanced-number/
// Language: C++ | Runtime: 544 ms | Memory: 254.7 MB

class Solution {
public:
    int nextBeautifulNumber(int n) {
        int x = n + 1;
        while (!isBalanced(x)) {
            x++;
        }
        return x;
    }

private:
    bool isBalanced(int num) {
        vector<int> count(10, 0);
        int orig = num;
        while (orig > 0) {
            int d = orig % 10;
            if (d == 0) return false;         // digit 0 cannot appear
            count[d]++;
            orig /= 10;
        }
        for (int d = 1; d <= 9; ++d) {
            if (count[d] > 0 && count[d] != d) return false;
        }
        return true;
    }
};
