#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int, int> lookup;
        for(int i = 0; i < numbers.size(); i++){
            lookup[numbers[i]] = i;
        }
        
        for(int i = 0; i < numbers.size(); i++){
            int complement = target - numbers[i];
            if(lookup.count(complement) && lookup[complement] != i){
                return {i + 1, lookup[complement] + 1};
            }
        }

        return {};
    }
};
