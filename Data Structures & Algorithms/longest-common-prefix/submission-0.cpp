class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string res = "";
        int i = 0;
        while(true){
            if(i >= strs[0].size()){
                return res;
            }

            for(auto& j :strs){
                if(j[i] != strs[0][i]){
                    return res;
                }
            }

            res += strs[0][i];
            i++;
        }

        return res;
    }
};