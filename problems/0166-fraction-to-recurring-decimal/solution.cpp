// 166. Fraction to Recurring Decimal [Medium]
// https://leetcode.com/problems/fraction-to-recurring-decimal/
// Language: C++ | Runtime: 0 ms | Memory: 9.3 MB

class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0) return "0";
        
        string result;
        
        // Handle negative sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        
        // Use absolute values (convert to long long to avoid overflow with INT_MIN)
        long long num = llabs(numerator);
        long long den = llabs(denominator);
        
        // Integer part
        result += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return result;
        
        result += ".";
        
        // Map remainder to its index in result
        unordered_map<long long, int> seen;
        
        while (rem != 0) {
            if (seen.count(rem)) {
                result.insert(seen[rem], "(");
                result += ")";
                break;
            }
            
            seen[rem] = result.size();
            rem *= 10;
            result += to_string(rem / den);
            rem %= den;
        }
        
        return result;
    }
};
