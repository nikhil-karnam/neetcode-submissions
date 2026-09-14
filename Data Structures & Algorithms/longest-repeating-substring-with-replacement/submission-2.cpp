#include <algorithm>
#include <vector>

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int l = 0;
        std::vector<int> f(26);
        
        for(int r = 0; r < s.size(); r++){
            f[s[r]-'A']++;
            int max_f = *std::max_element(f.begin(), f.end());
            
            //invalid
            while(!(r - l + 1 - max_f <= k)){
                f[s[l]-'A']--;
                l++;
                max_f = *std::max_element(f.begin(), f.end());
            }

            res = std::max(res, r-l+1);
        }
        return res;
    }
};
