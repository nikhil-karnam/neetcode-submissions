class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> dest(numCourses);
        std::vector<int> num_origins(numCourses);

        for(auto& i : prerequisites){
            num_origins[i[0]]++;
            dest[i[1]].push_back(i[0]);
        }

        std::queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(!num_origins[i]){
                q.push(i);
            }
        }

        while(!q.empty()){
            for(auto& i : dest[q.front()]){
                num_origins[i]--;
                if(num_origins[i] == 0){
                    q.push(i);
                }
            }
            q.pop();
        }

        for(auto& i : num_origins){
            if(i > 0){
                return false;
            }
        }
        return true;
    }
};
