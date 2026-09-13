#include <array>
#include <string>

class Solution {
public:
    bool valid(std::array<int, 58>& s, std::array<int, 58>& t){
        for(int i = 0; i < t.size(); i++){
            if(t[i] > s[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }

        std::array<int, 58> ft = {0}, fs = {0};
        for(auto c : t){
            ft[c-'A']++;
        }

        int l = 0, r = 0;
        int l_best = 0, r_best = 1e8;

        for(int r = 0; r < s.size(); r++){
            fs[s[r]-'A']++;
            while(r-l+1 >= t.size() && valid(fs, ft)){
                if(r-l+1 < r_best-l_best+1){
                    l_best = l;
                    r_best = r;
                }
                fs[s[l]-'A']--;
                l++;
            }
        }
        
        if(r_best == 1e8){
            return "";
        }
        return s.substr(l_best, r_best-l_best+1);
    }
};
