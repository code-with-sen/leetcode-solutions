// 1352. Product of the Last K Numbers [Medium]
// https://leetcode.com/problems/product-of-the-last-k-numbers/
// Language: C++ | Runtime: 98 ms | Memory: 97.8 MB

class ProductOfNumbers {
public:
    vector<int> pre = {1};

    ProductOfNumbers() {
    }
    
    void add(int num) {
        if (num == 0) {
            pre = {1};
        } else {
            pre.push_back(pre.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = pre.size();
        if (k >= n) {
            return 0;
        }
        return pre[n - 1] / pre[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
