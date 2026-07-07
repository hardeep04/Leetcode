class Solution {
public:
    bool isvalid(vector<vector<char>>& board, char x, int row, int col){
        for(int i=0; i<9; i++){
            if(board[row][i]==x || board[i][col]==x) return 0;
        }
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(i/3 == row/3 && j/3 == col/3 && board[i][j] == x) return 0;
            }
        }
        return 1;
    }
    bool solve(vector<vector<char>>& board){
        int row,col;
        bool filled=1;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    row=i;
                    col=j;
                    filled=0;
                    break;
                }
            }
            if(!filled) break;
        }
        
        if(filled) return 1;

        for(int i=1; i<=9; i++){
            if(isvalid(board,i+'0',row,col)){
                board[row][col]=i+'0';
                if(solve(board)) return 1;
                board[row][col]='.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};