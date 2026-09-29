class Solution {
public:
    bool fun(vector<vector<char>>& grid, int i , int j, int x,int dp[101][101][200]){
        int n=grid.size(), m=grid[0].size();
        if(x<0) return 0;
        if(i==n-1 && j==m-1){
            if(x==0) return 1;
            return 0;
        }
        if(dp[i][j][x] != -1) return dp[i][j][x];
        bool right = 0, down=0;
        if(j<m-1){
            if(grid[i][j+1] == '(') right = fun(grid, i, j+1, x+1, dp);
            else right = fun(grid, i, j+1, x-1, dp);
        }
        if(i<n-1){
            if(grid[i+1][j] == '(') down = fun(grid, i+1, j, x+1, dp);
            else down = fun(grid, i+1, j, x-1, dp);
        }
        return dp[i][j][x] = right | down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(n==1 && m==1) return 0;
        int dp[101][101][200];
        memset(dp, -1, sizeof(dp));
        return fun(grid, 0,0,grid[0][0]=='(', dp);

    }
};