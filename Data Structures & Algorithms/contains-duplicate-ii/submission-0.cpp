#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> m;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            if(r-l+1 > k + 1){
                m[nums[l]]--;
                l++;
            }
            if(m[nums[r]]){
                return true;
            }
            m[nums[r]]++;
        }
        return false;
    }
};