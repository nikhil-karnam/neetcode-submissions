#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        std::string t;
        for(auto i : s){
            if(std::isalnum(i)){
                t += std::tolower(i);
            }
        }

        for(int i = 0; i < t.size()/2; i++){
            if(t[i] != t[t.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
};
