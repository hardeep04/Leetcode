class Solution {
public:
    // int fun(vector<vector<int>>& grid, int i, int j, int j2, int dp[71][71][71]){
    //     int n=grid.size(), m=grid[0].size();
    //     if(i>=n || j<0 || j>=m || j2<0 || j2>=m) return -1e9;
    //     if(dp[i][j][j2]!=-1) return dp[i][j][j2];
    //     if(i==n-1){
    //         if(j==j2) return grid[i][j];
    //         else return grid[i][j] + grid[i][j2];
    //     }
    //     vector<int> ds = {-1,0,1};
        
    //     int maxi=0;
    //     for(int k=0; k<3; k++){
    //         for(int l=0; l<3; l++){
    //             int temp = grid[i][j] + fun(grid, i+1, j+ds[k], j2+ds[l],dp);
    //             if(j!=j2) temp+=grid[i][j2];
    //             maxi = max(maxi,temp);
    //         }
    //     }
    //     return dp[i][j][j2] = maxi;
    // }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        // int dp[71][71][71];
        // memset(dp, -1, sizeof(dp));
        // return fun(grid, 0, 0,m-1,dp);
        
        vector<vector<int>> prev(m, vector<int>(m, 0));
        for(int j=0; j<m; j++){
            for(int j2=0; j2<m; j2++){
                if(j==j2) prev[j][j2] = grid[n-1][j];
                else prev[j][j2] = grid[n-1][j] + grid[n-1][j2];
            }
        }

        for(int i=n-2; i>=0; i--){
            vector<vector<int>> curr(m, vector<int>(m, 0));
            for(int j=0; j<m; j++){
                for(int j2=0; j2<m; j2++){
                    for(int k=-1; k<2; k++){
                        for(int l=-1; l<2; l++){
                            int temp = grid[i][j];
                            if(j!=j2) temp+=grid[i][j2];
                            if(j+k>=0 && j2+l>=0 && j+k < m && j2+l < m) temp+=prev[j+k][j2+l];
                            else temp=-1e9;
                            curr[j][j2] = max(curr[j][j2],temp);
                        }
                    }
                    
                }
            }
            prev=curr;
        }
        return prev[0][m-1];
    }
};