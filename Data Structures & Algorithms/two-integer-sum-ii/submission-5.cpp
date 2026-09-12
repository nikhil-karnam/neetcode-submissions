#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int l = 0, r = numbers.size() -1; l < r;){
            for(; numbers[r] + numbers[l] > target; r--);
            for(; numbers[l] + numbers[r] <= target; l++){
                if(numbers[l] + numbers[r] == target){
                    return {l + 1, r + 1};
                }
            }
        }
        return  {};
    }
};
