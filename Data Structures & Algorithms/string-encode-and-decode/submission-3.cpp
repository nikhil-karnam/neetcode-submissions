#include <vector>
#include <string>

class Solution {
public:

    string encode(vector<string>& strs) {
        std::string s;
        for(auto i : strs){
            s += std::to_string(i.size()) + "#" + i;
        }
        return s;
    }

    vector<string> decode(string s) {
        std::vector<std::string> v;
        for(int i = 0; i < s.size();){
            std::string len;
            for(; s[i] != '#'; i++){
                len += s[i];
            }
            int len_int = std::stoi(len);
            std::string curr;
            for(i++; len_int > 0; len_int--, i++){
                curr += s[i];
            }
            v.push_back(curr);
        }
        return v;
    }
};
