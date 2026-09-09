#include <unordered_set>
#include <vector>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> all(nums.begin(), nums.end());
        int max_len = 0;
        for(auto i : nums){
            //starting candidate if it's the first in a sequence
            if(!all.count(i-1)){
                int len = 1;
                for(int curr = i+1; all.count(curr); curr++, len++);
                if(len > max_len){
                    max_len = len;
                }
            }
        }

        return max_len;    
    }
};
