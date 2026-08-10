class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){
        int n=grid.size(), m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return;
        vis[i][j]=1;
        if(i<n-1 && grid[i+1][j]==1 && !vis[i+1][j]) dfs(grid,i+1,j,vis);
        if(i>0 && grid[i-1][j]==1 && !vis[i-1][j]) dfs(grid,i-1,j,vis);
        if(j<m-1 && grid[i][j+1]==1 && !vis[i][j+1]) dfs(grid,i,j+1,vis);
        if(j>0 && grid[i][j-1]==1 && !vis[i][j-1]) dfs(grid,i,j-1,vis);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1 && !vis[i][0]) dfs(grid,i,0,vis);
            if(grid[i][m-1] == 1 && !vis[i][m-1]) dfs(grid,i,m-1,vis);
        }
        for(int j=0; j<m; j++){
            if(grid[0][j] == 1 && !vis[0][j]) dfs(grid,0,j,vis);
            if(grid[n-1][j] == 1 && !vis[n-1][j]) dfs(grid,n-1,j,vis);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]) ans++;
            }
        }
        return ans;
    }
};