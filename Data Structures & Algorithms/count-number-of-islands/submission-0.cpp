class Solution {
    std::vector<std::vector<bool>> visited;
public:
    void dfs(std::vector<std::vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() ||
        visited[i][j] ||
        grid[i][j] == '0'){
            return;
        }
        visited[i][j] = true;
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        visited.assign(grid.size(), std::vector<bool>(grid[0].size(), false));
        int islands = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }
};
