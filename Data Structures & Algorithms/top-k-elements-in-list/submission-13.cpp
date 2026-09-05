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

        bool* sorted = new bool[nums.size() + 1]();
        std::unordered_map<int, std::vector<int>> rev;
        for(auto i : counts){
            rev[i.second].push_back(i.first);
            sorted[i.second] = true;
        }

        std::vector<int> res = {};
        int count = 0;
        for(int i = nums.size(); i >= 0; i--){
            if(count != k && sorted[i]){
                for(auto j : rev[i]){
                    res.push_back(j);
                }
                count += rev[i].size();
            }
        }

        delete[] sorted;
        return res;
    }
};
