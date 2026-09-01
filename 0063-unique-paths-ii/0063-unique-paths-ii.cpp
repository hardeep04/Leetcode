class Solution {
public:
    int fun(int i,int j, int m, int n,vector<vector<int>>& v,vector<vector<int>>& dp){
        if(i>=m || j>=n || v[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = fun(i+1, j, m, n,v,dp);
        int right = fun(i, j+1, m, n,v,dp);
        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m=v.size(), n=v[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return fun(0,0,m,n,v,dp);
    }
};