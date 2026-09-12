#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> m;
        int max_len = 0;
        int starting = 0;
        for(int i = 0; i < s.size(); i++){
            /*if a character is repeated in the array, if it occurs before the
            starting point of the substring, then we're safe. the substring
            remains unique. if it occurs after the starting point, the rules are
            broken. every character in the substring is unique except for that
            character. so we set the new starting point to be the latest occurrence
            of that character + 1, which is within the substring.*/
            if(m.count(s[i]) && m[s[i]] >= starting){
                starting = m[s[i]] + 1;
            }
            max_len = std::max(max_len, i - starting + 1);
            m[s[i]] = i;
        }

        return max_len;
    }
};
