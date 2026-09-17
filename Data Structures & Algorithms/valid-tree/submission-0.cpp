class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> dest(n);
        for(auto& i : edges){
            dest[i[0]].push_back(i[1]);
            dest[i[1]].push_back(i[0]);
        }

        std::vector<bool> done(n, false);
        std::queue<std::pair<int, int>> q;
        q.push({0,0});
        done[0] = true;
        
        while(!q.empty()){
            for(auto& i : dest[q.front().first]){
                if(i != q.front().second){
                    if(done[i]){
                        return false;
                    }
                    q.push({i, q.front().first});
                    done[i] = true;
                }
            }
            q.pop();
        }

        for(auto i : done){
            if(!i){
                return false;
            }
        }

        return true;
    }
};
