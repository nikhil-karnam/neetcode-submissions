#include <algorithm>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        //most time possibly taken is the size of the biggest pile.
        //if you make k bigger than this, you still can't finish faster.
        int high = *std::max_element(piles.begin(), piles.end());
        //find lowest value of k where it passes.
        while(low < high){
            int k = (low + high) / 2;
            int hours = 0;
            for(auto p : piles){
                hours += p / k;
                if(p % k > 0){
                    hours++;
                }
            }
            if (hours <= h){ //pased
                high = k;
            }
            else{
                low = k + 1;
            }
        }

        return low;
    }
};
