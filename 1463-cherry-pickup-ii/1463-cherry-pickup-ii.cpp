class Solution {
public:
    int fun(vector<vector<int>>& grid, int i, int j, int j2, int dp[71][71][71]){
        int n=grid.size(), m=grid[0].size();
        if(i>=n || j<0 || j>=m || j2<0 || j2>=m) return -1e9;
        if(dp[i][j][j2]!=-1) return dp[i][j][j2];
        if(i==n-1){
            if(j==j2) return grid[i][j];
            else return grid[i][j] + grid[i][j2];
        }
        vector<int> ds = {-1,0,1};
        
        int maxi=0;
        for(int k=0; k<3; k++){
            for(int l=0; l<3; l++){
                int temp = grid[i][j] + fun(grid, i+1, j+ds[k], j2+ds[l],dp);
                if(j!=j2) temp+=grid[i][j2];
                maxi = max(maxi,temp);
            }
        }
        return dp[i][j][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int dp[71][71][71];
        memset(dp, -1, sizeof(dp));
        return fun(grid, 0, 0,m-1,dp);
    }
};