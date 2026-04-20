// 3906. Count Good Integers on a Grid Path [Hard]
// https://leetcode.com/problems/count-good-integers-on-a-grid-path/
// Language: C++ | Runtime: 15 ms | Memory: 11.8 MB

class Solution {
public:
    vector<int> pathIdx;

    long long dp[17][11][2];

    long long solve(string &num, int pos, int last, bool tight) {
        if (pos == 16) return 1;

        int lastIdx = last + 1; // shift (-1 → 0, 0→1 ... 9→10)

        if (dp[pos][lastIdx][tight] != -1) return dp[pos][lastIdx][tight];

        int limit = tight ? num[pos] - '0' : 9;
        long long res = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            bool isPath = false;
            for (int idx : pathIdx) {
                if (idx == pos) {
                    isPath = true;
                    break;
                }
            }

            if (isPath) {
                if (last != -1 && d < last) continue;
                res += solve(num, pos + 1, d, ntight);
            } else {
                res += solve(num, pos + 1, last, ntight);
            }
        }

        return dp[pos][lastIdx][tight] = res;
    }

    long long countUpTo(long long x) {
        if (x < 0) return 0;

        string num = to_string(x);
        while (num.size() < 16) num = "0" + num;

        memset(dp, -1, sizeof(dp));
        return solve(num, 0, -1, 1);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions) {

        int rpos = 0, cpos = 0;
        pathIdx.clear();
        pathIdx.push_back(0);

        for (char ch : directions) {
            if (ch == 'D') rpos++;
            else cpos++;
            pathIdx.push_back(rpos * 4 + cpos);
        }

        return countUpTo(r) - countUpTo(l - 1);
    }
};
