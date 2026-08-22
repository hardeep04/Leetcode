class Solution {
public:
    bool valid(vector<vector<int>>& grid,int n, int r, int c,vector<vector<bool>>& vis){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c] || vis[r][c]) return 0;
        return 1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]) return -1;
        queue<tuple<int,int,int>> q;
        q.push(make_tuple(1,0,0));
        vector<int> dr = {-1,-1,0,1,1,1,0,-1};
        vector<int> dc = {0,1,1,1,0,-1,-1,-1};
        // vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        // dist[0][0]=1;
        vis[0][0]=1;
        while(!q.empty()){
            auto [dis,r,c] = q.front();
            q.pop();
            if(r==n-1 && c==n-1) return dis;
            for(int i=0; i<8; i++){
                if(valid(grid,n,r+dr[i], c+dc[i],vis)){
                    q.push(make_tuple(dis+1,r+dr[i], c+dc[i]));
                    vis[r+dr[i]][c+dc[i]]=1;
                }
            }
        }
        return -1;
    }
};