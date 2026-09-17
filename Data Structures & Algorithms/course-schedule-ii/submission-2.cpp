class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> num_origins(numCourses);
        std::vector<std::vector<int>> dest(numCourses);
        for(auto& i : prerequisites){
            num_origins[i[0]]++;
            dest[i[1]].push_back(i[0]);
        }

        std::queue<int> q;
        for(int i = 0; i < num_origins.size(); i++){
            if(num_origins[i] == 0){
                q.push(i);
            }
        }

        std::vector<int> res;
        while(!q.empty()){
            int taking = q.front();
            res.push_back(taking);
            for(auto& i : dest[taking]){
                num_origins[i]--;
                if(num_origins[i] == 0){
                    q.push(i);
                }
            }
            q.pop();
        }

        for(auto& i : num_origins){
            if(i > 0){
                return {};
            }
        }
        return res;
    }
};
