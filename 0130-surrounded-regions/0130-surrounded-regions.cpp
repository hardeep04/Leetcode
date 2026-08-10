class Solution {
public:
    void fun(vector<vector<char>>& v, int i, int j,vector<vector<bool>>& vis){
        int n=v.size(), m=v[0].size();
        if(i>=n || j>=m || i<0 || j<0 || v[i][j]=='X') return;
        vis[i][j]=1;
        if(i<n-1 && v[i+1][j]=='O' && !vis[i+1][j]) fun(v,i+1,j,vis);
        if(i>0 && v[i-1][j]=='O' && !vis[i-1][j]) fun(v,i-1,j,vis);
        if(j>0 && v[i][j-1]=='O' && !vis[i][j-1]) fun(v,i,j-1,vis);
        if(j<m-1 && v[i][j+1]=='O' && !vis[i][j+1]) fun(v,i,j+1,vis);

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int j=0; j<m; j++){
            if(board[0][j]=='O' && !vis[0][j]){
                fun(board, 0,j,vis);
            }
        }
        for(int j=0; j<m; j++){
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                fun(board, n-1,j,vis);
            }
        }
        for(int i=0; i<n; i++){
            if(board[i][0]=='O' && !vis[i][0]){
                fun(board,i,0,vis);
            }
        }
        for(int i=0; i<n; i++){
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                fun(board,i,m-1,vis);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};