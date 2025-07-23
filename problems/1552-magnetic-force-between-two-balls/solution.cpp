// 1552. Magnetic Force Between Two Balls [Medium]
// https://leetcode.com/problems/magnetic-force-between-two-balls/
// Language: C++ | Runtime: 43 ms | Memory: 61.8 MB

class Solution {
public:
    bool canplaceball(vector<int>& position , int m , int mindist){
        int count = 1 ;
        int lastpos = position[0];
        for(int i = 0 ; i < position.size() ; i++){
            if( position[i] - lastpos >= mindist){
                count++;
                lastpos = position[i];
                if(count == m ) return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1 ;
        int high = position.back() - position.front();
        int ans = 0 ;

        while(low <= high){
            int med = low + (high - low )/2;
            if(canplaceball(position, m , med)){
                ans = med ;
                low = med + 1 ;
            }else {
                high = med - 1;
            }
        }
        return ans ;
    }
};
