// 1625. Lexicographically Smallest String After Applying Operations [Medium]
// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
// Language: C++ | Runtime: 247 ms | Memory: 116.6 MB

class Solution {
public:
    string addOperation(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = (s[i] - '0' + a) % 10 + '0';
        }
        return s;
    }

    string rotateOperation(string s, int b) {
        int n = s.size();
        b %= n;
        return s.substr(n - b) + s.substr(0, n - b);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> seen;
        queue<string> q;
        string ans = s;

        q.push(s);
        seen.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if (cur < ans) ans = cur;

            // Operation 1: add a to odd indices
            string added = addOperation(cur, a);
            if (!seen.count(added)) {
                seen.insert(added);
                q.push(added);
            }

            // Operation 2: rotate right by b
            string rotated = rotateOperation(cur, b);
            if (!seen.count(rotated)) {
                seen.insert(rotated);
                q.push(rotated);
            }
        }
        return ans;
    }
};
