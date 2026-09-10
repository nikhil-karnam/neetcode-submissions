#include <queue>

class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i : nums){
            q.push(i);
            if(q.size() > k){
                q.pop();
            }
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > k){
            q.pop();
        }
        return q.top();
    }
};
