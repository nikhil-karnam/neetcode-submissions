#include <queue>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, 
        decltype([](const auto& a, const auto& b) {
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);})> q;
        
        for(auto p : points){
            q.push(p);
            if(q.size() > k){
                q.pop();
            }
        }

        std::vector<std::vector<int>> res;
        while(k--){
            res.push_back(q.top());
            q.pop();
        }

        return res;
    }
};
