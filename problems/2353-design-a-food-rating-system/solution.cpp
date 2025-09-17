// 2353. Design a Food Rating System [Medium]
// https://leetcode.com/problems/design-a-food-rating-system/
// Language: C++ | Runtime: 119 ms | Memory: 162.6 MB

class FoodRatings {
    // Maps each food to its cuisine and rating
    unordered_map<string, pair<string, int>> foodInfo;
    // Maps cuisine -> ordered set of { -rating, food } (negative rating to sort descending)
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        // remove old entry
        cuisineFoods[cuisine].erase({-oldRating, food});
        // insert new entry
        cuisineFoods[cuisine].insert({-newRating, food});
        // update in foodInfo
        foodInfo[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        // first element of set is highest rated (because we stored -rating)
        return cuisineFoods[cuisine].begin()->second;
    }
};
