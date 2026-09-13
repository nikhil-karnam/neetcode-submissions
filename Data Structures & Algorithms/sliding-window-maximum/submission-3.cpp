#include <deque>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> q;
        for(int r = 0; r < k; r++){
            while(!q.empty() && nums[r] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(r);
        }

        std::vector<int> res = {nums[q.front()]};

        for(int r = k; r < nums.size(); r++){
            while(!q.empty() && nums[r] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(r);
            //you're always pushing back a valid index first, so no need !q.empty after
            while(q.front() <=  r - k){
                q.pop_front();
            }

            res.push_back(nums[q.front()]);
        }

        return res;
    }
};
