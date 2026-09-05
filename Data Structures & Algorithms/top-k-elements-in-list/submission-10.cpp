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

        bool* there_is = new bool[nums.size() + 1]();
        std::vector<int>* sorted = new std::vector<int>[nums.size() + 1];
        for(auto i : counts){
            sorted[i.second].push_back(i.first);
            there_is[i.second] = true;
        }

        std::vector<int> res = {};
        int count = 0;
        for(int i = nums.size(); i >= 0; i--){
            if(count != k && there_is[i]){
                for(auto j : sorted[i]){
                    res.push_back(j);
                }
                count+=sorted[i].size();
            }
        }

        delete[] there_is;
        delete[] sorted;
        return res;
    }
};
