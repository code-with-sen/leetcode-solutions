// 2013. Detect Squares [Medium]
// https://leetcode.com/problems/detect-squares/
// Language: C++ | Runtime: 35 ms | Memory: 102.3 MB

class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> cnt;
    // cnt[x][y] = number of points at (x, y)

public:
    DetectSquares() {}

    void add(vector<int> p) {
        int x = p[0], y = p[1];
        cnt[x][y]++;
    }

    int count(vector<int> p) {
        int x = p[0], y = p[1];
        int res = 0;

        for (auto& [col, c]: cnt[x]) {
            int d = col - y;
            if (d == 0) continue;

            // check other two corners
            res += c * cnt[x + d][y] * cnt[x + d][col];
            res += c * cnt[x - d][y] * cnt[x - d][col];
        }

        return res;
    }
};
