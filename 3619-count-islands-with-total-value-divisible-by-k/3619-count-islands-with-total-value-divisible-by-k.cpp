class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int i, int j){
        int n=grid.size(), m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return 0;

        long long ans = grid[i][j];
        grid[i][j] = 0;
        return ans + dfs(grid, i-1, j) + dfs(grid, i+1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0){
                    long long x = dfs(grid, i, j);
                    if(x%k == 0) ans++;
                }
            }
        }
        return ans;
    }
};