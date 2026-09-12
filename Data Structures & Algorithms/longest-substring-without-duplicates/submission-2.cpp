#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> m;
        int max_len = 0;
        int starting = 0;
        for(int i = 0; i < s.size(); i++){
            if(m.count(s[i]) && m[s[i]] >= starting){
                starting = m[s[i]] + 1;
            }
            max_len = std::max(max_len, i - starting + 1);
            m[s[i]] = i;
        }

        return max_len;
    }
};
