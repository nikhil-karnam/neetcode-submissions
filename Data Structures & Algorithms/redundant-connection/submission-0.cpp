#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for(auto& i : edges){
            n = std::max(n, i[0]);
            n = std::max(n, i[1]);
        }
        
        std::vector<std::vector<int>> dest(n+1);
        for(auto& i : edges){
            dest[i[0]].push_back(i[1]);
            dest[i[1]].push_back(i[0]);
        }

        std::vector<int> num_dest(n+1);
        for(int i = 1; i <= n; i++){
            num_dest[i] = dest[i].size();
        }

        std::queue<int> q;
        std::vector<bool> done(n+1);
        for(int i = 1; i <= n; i++){
            if(num_dest[i] == 1){
                q.push(i);
                done[i] = true;
            }
        }
        while(!q.empty()){
            int curr = q.front();
            //guaranteed there's only one neighbor that's not done
            for(auto& nei : dest[curr]){
                if(!done[nei]){
                    num_dest[nei]--;
                    if(num_dest[nei]==1){
                        q.push(nei);
                        done[nei] = true;
                    }
                }
            }
            q.pop();
        }

        std::unordered_set<int> in_cycle;
        for(int i = 1; i <= n; i++){
            if(!done[i]){
                in_cycle.insert(i);
            }
        }
        for(int i = edges.size()-1; i >= 0; i--){
            if(in_cycle.count(edges[i][0]) && in_cycle.count(edges[i][1])){
                return {edges[i]};
            }
        } 
        return {};
    }
};
