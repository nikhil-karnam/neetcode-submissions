#include <deque>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> q;
        std::vector<int> res;
        for(int r = 0; r < nums.size(); r++){
            while(!q.empty() && nums[r] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(r);
            //always pushing back a valid index first, so no need !q.empty after
            while(q.front() <=  r - k){
                q.pop_front();
            }
            
            if(r >= k - 1){
                res.push_back(nums[q.front()]);
            }
        }

        return res;
    }
};
