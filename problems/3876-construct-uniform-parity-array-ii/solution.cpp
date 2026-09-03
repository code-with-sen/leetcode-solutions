// 3876. Construct Uniform Parity Array II [Medium]
// https://leetcode.com/problems/construct-uniform-parity-array-ii/
// Language: C++ | Runtime: 0 ms | Memory: 165.8 MB

class Solution {
public:
    bool uniformArray(auto& A) {
        uint32_t x[2] = {-1u, -1u};

        for (uint32_t a : A)
            x[a & 1] = min(x[a & 1], a);

        //TRUE IF: The min is odd || ∄ Odd elements  
        return x[1] < x[0] | x[1] == -1u;
    }
};
