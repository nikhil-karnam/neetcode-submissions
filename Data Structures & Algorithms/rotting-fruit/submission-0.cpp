#include <vector>
#include <queue>

class Solution {
private:
    struct Fruit{
        int i, j, timestamp;
    };

    int valid(std::vector<std::vector<int>>& grid, int i, int j){
        return i>=0 && i<grid.size() && j>=0 && j<grid[i].size();
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::queue<Fruit> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
            }
        }

        int ts = 0;
        while(!q.empty()){
            int i = q.front().i;
            int j = q.front().j;
            ts = q.front().timestamp;
            if(valid(grid,i-1,j) && grid[i-1][j]==1){
                grid[i-1][j] = 2;
                q.push({i-1,j,ts+1});
            }
            if(valid(grid,i+1,j) && grid[i+1][j]==1){
                grid[i+1][j] = 2;
                q.push({i+1,j,ts+1});
            }
            if(valid(grid,i,j-1) && grid[i][j-1]==1){
                grid[i][j-1] = 2;
                q.push({i,j-1,ts+1});
            }
            if(valid(grid,i,j+1) && grid[i][j+1]==1){
                grid[i][j+1] = 2;
                q.push({i,j+1,ts+1});
            }
            q.pop();
        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ts;
    }
};
