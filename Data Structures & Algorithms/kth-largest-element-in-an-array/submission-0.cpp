#include <queue>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        for(auto i : nums){
            q.push(i);
            if(q.size() > k){
                q.pop();
            }
        }

        return q.top();
    }
};
