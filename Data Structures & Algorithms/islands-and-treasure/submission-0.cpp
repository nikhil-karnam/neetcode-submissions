#include <queue>

class Solution {
public:
    bool valid(std::vector<std::vector<int>>& grid, int i, int j){
        return i>=0 && i<grid.size() && j>=0 && j<grid[0].size();
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::queue<std::pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            if(valid(grid, i-1, j) && grid[i-1][j]==(1LL<<31)-1){
                q.push({i-1,j});
                grid[i-1][j] = grid[i][j] + 1;
            }
            if(valid(grid, i+1, j) && grid[i+1][j]==(1LL<<31)-1){
                q.push({i+1,j});
                grid[i+1][j] = grid[i][j] + 1;
            }
            if(valid(grid, i, j-1) && grid[i][j-1]==(1LL<<31)-1){
                q.push({i,j-1});
                grid[i][j-1] = grid[i][j] + 1;
            }
            if(valid(grid, i, j+1) && grid[i][j+1]==(1LL<<31)-1){
                q.push({i,j+1});
                grid[i][j+1] = grid[i][j] + 1;
            }
            q.pop();
        }
        
    }
};
