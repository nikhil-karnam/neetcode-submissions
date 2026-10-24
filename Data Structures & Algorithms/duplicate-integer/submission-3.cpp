class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> m;
        for(auto& i : nums){
            if(m.count(i)){
                return true;
            }
            m[i]++;
        }

        return false;
    }
};