// 3483. Unique 3-Digit Even Numbers [Easy]
// https://leetcode.com/problems/unique-3-digit-even-numbers/
// Language: C++ | Runtime: 0 ms | Memory: 28.9 MB

class Solution {
public:
    int totalNumbers(auto& digits) {
        int f[10] = {0};
        int res = 0;

        for (auto& d : digits)
            f[d]++;

        for (int i = 1; i < 10; i++) 
            for (int j = 0; j < 10; j++) 
                for (int k = 0; k < 9; k += 2) 
                    res += f[i] > 0 &&
                           f[j] > (i == j) &&
                           f[k] > (i == k) + (j == k);
        

        return res;
    }
};
