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


        std::vector<std::vector<int>> res_a, res_p;

        auto p = pacific;
        while(!p.empty()){
            done[p.front().first][p.front().second] = true;
            p.pop();
        }
        while(!pacific.empty()){
            int i = pacific.front().first;
            int j = pacific.front().second;

            res_p.push_back({i,j});

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

            res_a.push_back({i,j});

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
        std::sort(res_a.begin(), res_a.end());
        std::sort(res_p.begin(), res_p.end());
        std::set_intersection(res_a.begin(), res_a.end(),
                              res_p.begin(), res_p.end(),
                              std::back_inserter(res));
        return res;
    }
};
