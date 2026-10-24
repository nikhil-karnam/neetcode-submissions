class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string res = "";
        int i = 0;
        while(true){
            std::string base = strs[0];
            if(i >= base.size()){
                return res;
            }
            char c = base[i];

            for(auto& j : strs){
                if(i >= j.size() || j[i] != c){
                    return res;
                }
            }

            res += c;
            i++;
        }

        return res;
    }
};