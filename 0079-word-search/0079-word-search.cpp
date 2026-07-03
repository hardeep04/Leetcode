class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx){
        int n = board.size(), m=board[0].size();
        if (idx == word.size()) return 1;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != word[idx]) return 0;

        char temp = board[i][j];
        board[i][j]='#';
        bool found = dfs(board, word, i+1,j,idx+1) || dfs(board, word, i-1,j,idx+1) || dfs(board, word, i,j+1,idx+1) || dfs(board, word, i,j-1,idx+1);

        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m=board[0].size();
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(dfs(board,word,r,c,0)) return 1;
            }
        }
        return 0;
    }
};