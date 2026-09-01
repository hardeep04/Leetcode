class Solution {
public:
    int fun(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& dp){
        int n=grid.size(), m=grid[0].size();
        if(i>=n || j>=m) return INT_MAX;
        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int left = fun(grid, i+1, j,dp);
        int right = fun(grid, i, j+1,dp);
        if(left == INT_MAX && right == INT_MAX) return grid[i][j];
        return dp[i][j] = grid[i][j] + min(left, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(n==1 && m==1) return grid[0][0]; 
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return fun(grid, 0, 0, dp);
    }
};