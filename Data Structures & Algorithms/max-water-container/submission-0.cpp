#include <algorithm>
#include <vector>

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_volume = 0;
        int l = 0;
        int r = heights.size() - 1;
        while(l < r){
            int volume = std::min(heights[l], heights[r]) * (r-l);
            if(volume > max_volume){
                max_volume = volume;
            }
            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }

        return max_volume;
    }
};
