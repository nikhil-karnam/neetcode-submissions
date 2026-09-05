#include<unordered_map>
#include<vector>
#include<array>
#include<string>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for(auto i : strs){
            std::array<int, 26> a = {};
            for(auto j : i){
                a[j-'a']++;
            }
            std::string key = "";
            for(auto counts : a){
                key += std::to_string(counts) + "#";
            }
            groups[key].push_back(i);
        }

        std::vector<std::vector<std::string>> res;
        for(auto i : groups){
            res.push_back(i.second);
        }
        return res;
    }
};
