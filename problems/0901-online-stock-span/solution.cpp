// 901. Online Stock Span [Medium]
// https://leetcode.com/problems/online-stock-span/
// Language: C++ | Runtime: 31 ms | Memory: 92.1 MB

class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};
