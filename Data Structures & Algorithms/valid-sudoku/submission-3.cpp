#include <vector>

class Solution {
public:
    bool dup(std::vector<char> v){
        std::vector<bool> present(v.size());
        for(int i = 0; i < v.size(); i++){
            if(v[i] != '.' && present[v[i]-'0']){
                return true;
            }
            if(v[i] != '.'){
                present[v[i]-'0'] = true;
            }
        }

        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {        
        for(auto i : board){
            if(dup(i)){
                return false;
            }
        }

        for(char c = 0; c < 9; c++){
            std::vector<char> v;
            for(char r = 0; r < 9; r++){
                v.push_back(board[r][c]);
            }
            if(dup(v)){
                return false;
            }
        }

        for(char i = 0; i < 9; i+=3){
            for(char j = 0; j < 9; j+=3){
                std::vector<char> v;
                for(char n = i; n < i+3; n++){
                    for(char m = j; m < j+3; m++){
                        v.push_back(board[n][m]);
                    }
                }
                
                if(dup(v)){
                    return false;
                }
            }
        }

        return true;
    }
};
