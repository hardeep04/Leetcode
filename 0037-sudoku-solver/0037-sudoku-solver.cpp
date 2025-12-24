class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row, int col, int num){
        for(int i=0; i<9; i++){
            if(board[i][col]==char(48+num)) return 0;
        }
        for(int i=0; i<9; i++){
            if(board[row][i]==char(48+num)) return 0;
        }
        int k = (row/3)*3 + col/3;
        for(int r = (row/3)*3; r<(row/3)*3+3; r++){
            for(int c = (col/3)*3; c<(col/3)*3+3; c++){
                if(board[r][c]==char(48+num)) return 0;
            }
        }
        return 1;
    }
    bool solve(vector<vector<char>>& board){
        int row,col;
        bool filled=1;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    row=i; col=j;
                    filled=0;
                    break;
                }
            }
            if(!filled) break;
        }
        if(filled) return 1;

        for(int num=1; num<=9; num++){
            if(issafe(board, row,col,num)){
                board[row][col]=char(48+num);
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