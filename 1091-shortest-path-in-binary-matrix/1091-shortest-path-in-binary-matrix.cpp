class Solution {
public:
    bool valid(vector<vector<int>>& grid,int n, int r, int c,vector<vector<bool>>& vis){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c] || vis[r][c]) return 0;
        return 1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> dr = {-1,-1,0,1,1,1,0,-1};
        vector<int> dc = {0,1,1,1,0,-1,-1,-1};
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        dist[0][0]=1; vis[0][0]=1;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i=0; i<8; i++){
                if(valid(grid,n,r+dr[i], c+dc[i],vis) && dist[r][c] + 1 < dist[r+dr[i]][c+dc[i]]){
                    dist[r+dr[i]][c+dc[i]] = dist[r][c]+1;
                    q.push({r+dr[i], c+dc[i]});
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};