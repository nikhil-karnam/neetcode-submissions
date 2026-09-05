#include <array>

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int, 26> a = {};
        std::array<int, 26> b = {};
        for(auto i : s){
            a[i-'a']++;
        }
        for(auto i : t){
            b[i-'a']++;
        }

        return a == b;
    }
};
