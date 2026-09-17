#include <vector>
#include <queue>
#include <algorithm>

class Solution {
private:
    bool valid(std::vector<std::vector<int>>& heights, int i, int j){
        return i>=0 && i<heights.size() && j>=0 && j<heights[0].size();
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.size() == 1 || heights[0].size() == 1){
            std::vector<std::vector<int>> res;
            for(int i = 0; i < heights.size(); i++){
                for(int j = 0; j < heights[0].size(); j++){
                    res.push_back({i,j});
                }
            }
            return res;
        }

        std::queue<std::pair<int,int>> pacific, atlantic;
        std::vector<std::vector<bool>> done(heights.size(), std::vector<bool>(heights[0].size(), false));
        for(int j = 0; j < heights[0].size(); j++){
            //pushing first and last row
            pacific.push({0,j});
            atlantic.push({heights.size()-1,j});
        }
        for(int i = 1; i < heights.size() - 1; i++){
            //push first and last column
            pacific.push({i,0});
            atlantic.push({i,heights[0].size()-1});
        }
        pacific.push({heights.size()-1,0});
        atlantic.push({0,heights[0].size()-1});


        std::vector<std::vector<int>> can_flow(heights.size(), std::vector<int>(heights[0].size()));

        auto p = pacific;
        while(!p.empty()){
            done[p.front().first][p.front().second] = true;
            p.pop();
        }
        while(!pacific.empty()){
            int i = pacific.front().first;
            int j = pacific.front().second;

            can_flow[i][j]++;

            if(valid(heights, i-1, j) && heights[i-1][j] >= heights[i][j] && !done[i-1][j]){
                pacific.push({i-1, j});
                done[i-1][j] = true;
            }
            if(valid(heights, i+1, j) && heights[i+1][j] >= heights[i][j] && !done[i+1][j]){
                pacific.push({i+1, j});
                done[i+1][j] = true;
            }
            if(valid(heights, i, j-1) && heights[i][j-1] >= heights[i][j] && !done[i][j-1]){
                pacific.push({i, j-1});
                done[i][j-1] = true;
            }
            if(valid(heights, i, j+1) && heights[i][j+1] >= heights[i][j] && !done[i][j+1]){
                pacific.push({i, j+1});
                done[i][j+1] = true;
            }
            pacific.pop();
        }

        for(auto& i : done){
            std::fill(i.begin(), i.end(), false);
        }

        auto a = atlantic;
        while(!a.empty()){
            done[a.front().first][a.front().second] = true;
            a.pop();
        }
        while(!atlantic.empty()){
            int i = atlantic.front().first;
            int j = atlantic.front().second;

            can_flow[i][j]++;

            if(valid(heights, i-1, j) && heights[i-1][j] >= heights[i][j] && !done[i-1][j]){
                atlantic.push({i-1, j});
                done[i-1][j] = true;
            }
            if(valid(heights, i+1, j) && heights[i+1][j] >= heights[i][j] && !done[i+1][j]){
                atlantic.push({i+1, j});
                done[i+1][j] = true;
            }
            if(valid(heights, i, j-1) && heights[i][j-1] >= heights[i][j] && !done[i][j-1]){
                atlantic.push({i, j-1});
                done[i][j-1] = true;
            }
            if(valid(heights, i, j+1) && heights[i][j+1] >= heights[i][j] && !done[i][j+1]){
                atlantic.push({i, j+1});
                done[i][j+1] = true;
            }
            atlantic.pop();
        }

        std::vector<std::vector<int>> res;
        for(int i = 0; i < can_flow.size(); i++){
            for(int j = 0; j < can_flow[0].size(); j++){
                if(can_flow[i][j] > 1){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
