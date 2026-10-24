class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            m[nums[i]] = i;
        }

        for(int i = 0; i < n; i++){
            int num = nums[i];
            int complement = target - num;
            if(m.count(complement) && m[complement] != i){
                return {i, m[complement]};
            }
        }
        
        return {};
    }
};
