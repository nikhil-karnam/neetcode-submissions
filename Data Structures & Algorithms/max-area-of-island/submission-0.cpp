class Solution {
private:
    int area;
    std::vector<std::vector<bool>> fkoff;
public:
    void dfs(std::vector<std::vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        fkoff[i][j] ||
        !grid[i][j]){
            return;
        }
        
        area++;
        fkoff[i][j] = true;
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        fkoff.assign(grid.size(), std::vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!fkoff[i][j] && grid[i][j]){
                    area = 0;
                    dfs(grid, i, j);
                    res = std::max(res, area);
                }
            }
        }

        return res;
    }
};
