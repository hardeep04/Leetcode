class Solution {
public:
    int fun(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int n=grid.size(), m=grid[0].size();
        if(i>=n || j>=m) return 1e6;
        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int d = grid[i][j] + fun(grid, i+1, j, dp);
        int r = grid[i][j] + fun(grid, i, j+1, dp);
        if(d == 1e6 && r == 1e6) return grid[i][j];
        return dp[i][j] = min(d,r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fun(grid, 0, 0, dp);
    }
};