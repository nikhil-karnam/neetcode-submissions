#include <unordered_map>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> counts = {};
        for(auto i : nums) {
            counts[i]++;
        }

        //bucket sort O(n) for counts, but each count is paired with a vector of its associated nums
        std::vector<std::vector<int>> sorted(nums.size() + 1);
        for(auto i : counts){
            sorted[i.second].push_back(i.first);
        }

        std::vector<int> res = {};
        for(int i = nums.size(); i >= 0 && k > 0; i--){
            //if the count was not present, vector will be empty and loop will skip and k will not update.
            for(auto j : sorted[i]){
                res.push_back(j);
            }
            k -= sorted[i].size();
        }

        return res;
    }
};
