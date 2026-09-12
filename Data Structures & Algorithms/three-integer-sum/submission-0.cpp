#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> res;

        for(int i = 0; i < nums.size(); i++){
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[l] + nums[r] + nums[i];
                if(sum == 0){
                    res.insert({nums[i], nums[l], nums[r]});
                }
                if(sum < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        
        std::vector<std::vector<int>> res_vec(res.begin(), res.end());
        return res_vec;
    }
};
