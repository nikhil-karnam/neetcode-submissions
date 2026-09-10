#include <array>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::array<int, 101> bucket{0};
        for(auto i : stones){
            bucket[i]++;
        }

        for(int i2 = 100, i1 = 99; i2 >= 0;i2--){
            for(; i2 >= 0 && bucket[i2] == 0; i2--);
            for(i1 = i2 - 1; i1 >= 0 && bucket[i1] == 0; i1--);
            
            if(i1 < 0){
                if(bucket[i2] % 2){
                    return i2;
                }
                return 0;
            }
            
            if(bucket[i2] % 2){
                bucket[i2-i1]++;
                bucket[i1]--;
            }
        }
        return 0;
    }
};
