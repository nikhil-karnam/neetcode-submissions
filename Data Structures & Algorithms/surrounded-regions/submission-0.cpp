class Solution {
private:
    bool valid(std::vector<std::vector<char>>& board, int i, int j){
        return i>=0 && i<board.size() && j>=0 && j<board[0].size();
    }
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        std::queue<std::pair<int, int>> q;
        for(int j = 0; j < c; j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                board[0][j] = '.';
            }
            if(board[r-1][j]=='O'){
                q.push({r-1,j});
                board[r-1][j] = '.';
            }
        }
        for(int i = 1; i < r-1; i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                board[i][0] = '.';
            }
            if(board[i][c-1]=='O'){
                q.push({i,c-1});
                board[i][c-1] = '.';
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            
            if(valid(board, i-1, j) && board[i-1][j]=='O'){
                q.push({i-1,j});
                board[i-1][j] = '.';
            }
            if(valid(board, i+1, j) && board[i+1][j]=='O'){
                q.push({i+1,j});
                board[i+1][j] = '.';
            }
            if(valid(board, i, j-1) && board[i][j-1]=='O'){
                q.push({i,j-1});
                board[i][j-1] = '.';
            }
            if(valid(board, i, j+1) && board[i][j+1]=='O'){
                q.push({i,j+1});
                board[i][j+1] = '.';
            }
            q.pop();
        }

        for(auto& i : board){
            for(auto& j : i){
                if(j=='O'){
                    j = 'X';
                }
                if(j=='.'){
                    j = 'O';
                }
            }
        }
    }
};
