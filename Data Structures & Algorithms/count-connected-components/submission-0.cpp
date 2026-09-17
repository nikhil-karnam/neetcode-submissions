class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> dest(n);
        for(auto& i : edges){
            dest[i[0]].push_back(i[1]);
            dest[i[1]].push_back(i[0]);
        }

        std::vector<bool> done(n);

        int res = 0;
        for(int i = 0; i < n; i++){
            if(!done[i]){
                res++;
                
                std::queue<int> q;
                q.push(i);
                done[i] = true;
                while(!q.empty()){
                    int curr = q.front();
                    for(auto& d : dest[curr]){
                        if(!done[d]){
                            q.push(d);
                            done[d] = true;
                        }
                    }
                    q.pop();
                }
            }
        }

        return res;
    }
};
