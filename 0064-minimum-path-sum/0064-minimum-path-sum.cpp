class Solution {
public:
    // int fun(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& dp){
    //     int n=grid.size(), m=grid[0].size();
    //     if(i>=n || j>=m) return INT_MAX;
    //     if(i==n-1 && j==m-1) return grid[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int left = fun(grid, i+1, j,dp);
    //     int right = fun(grid, i, j+1,dp);
    //     if(left == INT_MAX && right == INT_MAX) return grid[i][j];
    //     return dp[i][j] = grid[i][j] + min(left, right);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(n==1 && m==1) return grid[0][0]; 
        // vector<vector<int>> dp(n, vector<int>(m,-1));
        // return fun(grid, 0, 0, dp);
        vector<int> prev(m);
        for(int i=n-1; i>=0; i--){
            vector<int> curr(m);
            for(int j=m-1; j>=0; j--){
                if (i == n - 1 && j == m - 1) {
                    curr[j] = grid[i][j];
                    continue;
                }
                int left=0, right=0;
                if(i<n-1) left += prev[j];
                else left=INT_MAX;
                if(j<m-1) right += curr[j+1];
                else right=INT_MAX;
                curr[j] = grid[i][j] + min(left, right);
            }
            prev=curr;
        }
        return prev[0];
    }
};