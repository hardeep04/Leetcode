class Solution {
public:
    // int fun(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    //     int n=grid.size(), m=grid[0].size();
    //     if(i>=n || j>=m) return 1e6;
    //     if(i==n-1 && j==m-1) return grid[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int d = grid[i][j] + fun(grid, i+1, j, dp);
    //     int r = grid[i][j] + fun(grid, i, j+1, dp);
    //     if(d == 1e6 && r == 1e6) return grid[i][j];
    //     return dp[i][j] = min(d,r);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return fun(grid, 0, 0, dp);
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n-1][m-1] = grid[n-1][m-1];
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1) continue;
                int d = grid[i][j];
                if(i<n-1) d+= dp[i+1][j];
                else d=INT_MAX;
                int r = grid[i][j];
                if(j<m-1) r+= dp[i][j+1];
                else r=INT_MAX;
                dp[i][j] = min(d,r);
            }
        }
        return dp[0][0];
    }
};