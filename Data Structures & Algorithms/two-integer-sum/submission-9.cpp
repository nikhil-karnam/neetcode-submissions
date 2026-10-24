class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(m.count(complement) && i != m[complement]){
                return {i, m[complement]};
            }
        }

        return {};
    }
};
