#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
            std::unordered_set<int> s = {};
            for(auto i : nums){
                if(s.count(i) > 0){
                    return true;
                }
                s.insert(i);
            }
            return false;
    }
};