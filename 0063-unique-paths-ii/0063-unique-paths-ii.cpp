class Solution {
public:
    int fun(int i,int j, int m, int n,vector<vector<int>>& v,vector<vector<int>>& dp){
        if(i>=m || j>=n || v[i][j]) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = fun(i+1, j, m, n,v,dp);
        int right = fun(i, j+1, m, n,v,dp);
        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m=v.size(), n=v[0].size();
        if(v[0][0]) return 0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        bool flag=0;
        for(int i=0; i<n; i++){
            if(v[0][i]) flag = 1;
            if(!flag) dp[0][i] = 1;
            else dp[0][i]=0;
        } 
        flag=0;
        for(int i=0; i<m; i++){
            if(v[i][0]) flag = 1;
            if(!flag) dp[i][0] = 1;
            else dp[i][0]=0;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(v[i][j]) dp[i][j]=0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};