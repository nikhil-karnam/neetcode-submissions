class Solution {
private:
    bool valid(std::vector<std::vector<char>>& grid, int a, int b){
        return a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size();
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        std::vector<std::vector<bool>> done(grid.size(), std::vector<bool>(grid[0].size()));

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!done[i][j] && grid[i][j] == '1'){
                    std::queue<std::pair<int, int>> q;
                    q.push({i,j});
                    done[i][j] = true;
                    while(!q.empty()){
                        int a = q.front().first;
                        int b = q.front().second;
                        
                        if(valid(grid, a-1, b) && !done[a-1][b] && grid[a-1][b] == '1'){
                            q.push({a-1, b});
                            done[a-1][b] = true;
                        }
                        if(valid(grid, a+1, b) && !done[a+1][b] && grid[a+1][b] == '1'){
                            q.push({a+1, b});
                            done[a+1][b] = true;
                        }
                        if(valid(grid, a, b-1) && !done[a][b-1] && grid[a][b-1] == '1'){
                            q.push({a, b-1});
                            done[a][b-1] = true;
                        }
                        if(valid(grid, a, b+1) && !done[a][b+1] && grid[a][b+1] == '1'){
                            q.push({a, b+1});
                            done[a][b+1] = true;
                        }

                        q.pop();
                    }
                    res++;
                }
            }
        }

        return res;
    }
};
