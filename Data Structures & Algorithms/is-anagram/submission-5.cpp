class Solution {
public:
    std::string haash(std::string& s){
        std::vector<int> freq(26);
        for(auto& i : s){
            freq[i-'a']++;
        }

        std::string res;
        for(auto& i : freq){
            res += std::to_string(i) + " ";
        }

        return res;
    }
    bool isAnagram(string s, string t) {
        return haash(s) == haash(t);
    }
};
