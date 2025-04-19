// 11. Container With Most Water [Medium]
// https://leetcode.com/problems/container-with-most-water/
// Language: C++ | Runtime: 0 ms | Memory: 62.9 MB

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0,right = height.size() -1;
        int mostwater = 0;
        while(left<right){
            int h = min(height[right],height[left]);
            int w= right - left;
            int area = h*w;

            mostwater = max(mostwater,area);

            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return mostwater;
    }
};
