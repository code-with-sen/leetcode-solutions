// 3479. Fruits Into Baskets III [Medium]
// https://leetcode.com/problems/fruits-into-baskets-iii/
// Language: C++ | Runtime: 83 ms | Memory: 189.2 MB

class SegmentTree {
public:
    SegmentTree(const vector<int>& arr) : n(arr.size()), tree(4 * n) {
        build(arr, 0, 0, n - 1);
    }

    // Finds the leftmost valid basket (index) with capacity >= target.
    // Also marks that basket as used (sets its value to -1).
    int findLeftmost(int target) {
        return query(0, 0, n - 1, target);
    }

private:
    int n;
    vector<int> tree;

    void build(const vector<int>& arr, int idx, int lo, int hi) {
        if (lo == hi) {
            tree[idx] = arr[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(arr, 2*idx+1, lo, mid);
        build(arr, 2*idx+2, mid+1, hi);
        tree[idx] = max(tree[2*idx+1], tree[2*idx+2]);
    }

    void update(int idx, int lo, int hi, int pos, int val) {
        if (lo == hi) {
            tree[idx] = val;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (pos <= mid) update(2*idx+1, lo, mid, pos, val);
        else update(2*idx+2, mid+1, hi, pos, val);
        tree[idx] = max(tree[2*idx+1], tree[2*idx+2]);
    }

    int query(int idx, int lo, int hi, int target) {
        if (tree[idx] < target) return -1;           // No possible basket here
        if (lo == hi) {
            update(0, 0, n - 1, lo, -1);             // Mark used
            return lo;
        }
        int mid = lo + (hi - lo) / 2;
        int left = tree[2*idx+1];
        if (left >= target) {
            return query(2*idx+1, lo, mid, target);
        } else {
            return query(2*idx+2, mid+1, hi, target);
        }
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        SegmentTree st(baskets);
        for (int f : fruits) {
            if (st.findLeftmost(f) == -1) unplaced++;
        }
        return unplaced;
    }
};
