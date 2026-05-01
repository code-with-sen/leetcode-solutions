// 904. Fruit Into Baskets [Medium]
// https://leetcode.com/problems/fruit-into-baskets/
// Language: C++ | Runtime: 41 ms | Memory: 84.8 MB

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> basket;
        int left = 0 , maxFruit = 0;

        for(int right = 0 ; right < fruits.size(); right++){
            basket[fruits[right]]++;

            while(basket.size() > 2){
                basket[fruits[left]]--;

                if(basket[fruits[left]] == 0){
                    basket.erase(fruits[left]);
                }

                left++;
            }

            maxFruit = max(maxFruit, right - left + 1);

        }

        return maxFruit;
    }
};
