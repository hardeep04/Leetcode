class Solution {
public:
    // int fun(int i,int j, int m, int n,vector<vector<int>>& v,vector<vector<int>>& dp){
    //     if(i>=m || j>=n || v[i][j]) return 0;
    //     if(i==m-1 && j==n-1) return 1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int down = fun(i+1, j, m, n,v,dp);
    //     int right = fun(i, j+1, m, n,v,dp);
    //     return dp[i][j] = down + right;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m=v.size(), n=v[0].size();
        if(v[0][0]) return 0;
        vector<int> prevRow(n);
        prevRow[0]=1;
        for(int i=1; i<n; i++){
            if(v[0][i]) prevRow[i]=0;
            else prevRow[i] = prevRow[i-1];
        }
        for(int i=1; i<m; i++){
            vector<int> currRow(n);
            for(int j=0; j<n; j++){
                if(v[i][j]) currRow[j]=0;
                else if(j==0) currRow[j] = prevRow[j];
                else currRow[j] = prevRow[j] + currRow[j-1];
            }
            prevRow = currRow;
        }
        return prevRow[n-1];
    }
};