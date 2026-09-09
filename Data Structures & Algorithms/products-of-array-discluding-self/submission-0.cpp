#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix_l(nums.size()+1), prefix_r(nums.size()+1);
        int curr_product = 1;
        prefix_l[0] = 1;
        prefix_r[nums.size()] = 1;
        
        for(int i = 0; i < nums.size(); i++){
            prefix_l[i] = curr_product;
            curr_product *= nums[i];
        }

        curr_product = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            prefix_r[i] = curr_product;
            curr_product *= nums[i];

        }

        std::vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            res.push_back(prefix_r[i] * prefix_l[i]);
        }

        return res;
    }
};
