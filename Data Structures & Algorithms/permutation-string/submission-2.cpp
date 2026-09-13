#include <array>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        
        std::array<int, 26> f_s2 = {0};
        std::array<int, 26> f_s1 = {0};
        for(int i = 0; i < s1.size(); i++){
            f_s1[s1[i]-'a']++;
            f_s2[s2[i]-'a']++;
        }
        
        if(f_s1 == f_s2){
            return true;
        }
        
        for(int i = s1.size(); i < s2.size(); i++){
            f_s2[s2[i]-'a']++;
            f_s2[s2[i-s1.size()]-'a']--;

            if(f_s1 == f_s2){
                return true;
            }
        }

        return false;
    }
};
