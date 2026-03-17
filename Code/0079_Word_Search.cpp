class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(auto i = 0; i < board.size(); i++){
            for(auto j = 0; j < board[0].size(); j++){
                if(word[0] == board[i][j]){
                    if(searchWord(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }

    bool searchWord(vector<vector<char>>& board, string word, int r, int c, int index){
        if(r == board.size() || c == board[0].size() || r < 0 || c < 0)
            return false;

        if(board[r][c] == '#')
            return false;

        if(word[index] != board[r][c]){
            return false;
        }

        char orig =  board[r][c];
        board[r][c] = '#';

        if(index == word.length()-1)
            return true;

        if(searchWord(board, word, r-1, c, index+1))
            return true;

        if(searchWord(board, word, r+1, c, index+1))
            return true;

        if(searchWord(board, word, r, c-1, index+1))
            return true;

        if(searchWord(board, word, r, c+1, index+1))
            return true;

        board[r][c] = orig;

        return false;
    }
};