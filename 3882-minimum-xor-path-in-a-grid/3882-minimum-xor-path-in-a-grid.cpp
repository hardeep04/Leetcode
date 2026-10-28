class Solution {
public:
    int ans = INT_MAX;
    
    void fun(vector<vector<int>>& grid, int i, int j, int x, vector<vector<vector<bool>>>& vis) {
        int n = grid.size(), m = grid[0].size();
        if (vis[i][j][x]) return;
        vis[i][j][x] = 1;        
        if (i == n-1 && j == m-1) {
            ans = min(ans, x);
            return;
        }        
        if (j+1<m) fun(grid, i, j + 1, x ^ grid[i][j + 1], vis);
        if (i+1<n) fun(grid, i + 1, j, x ^ grid[i + 1][j], vis);
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(1024, 0)));
        fun(grid, 0, 0, grid[0][0], vis);
        return ans;
    }
};