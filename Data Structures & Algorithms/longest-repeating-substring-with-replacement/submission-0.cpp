#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> m;
        int res = 0;
        int l = 0;
        int max_f = 0;
        for(int r = 0; r < s.size(); r++){
            m[s[r]]++;
            max_f = std::max(max_f, m[s[r]]);
            if(r-l+1 > max_f + k){
                m[s[l]]--;
                l++;
            }
            res = std::max(res, r-l+1);
        }
        return res;
    }
};
