class Solution {
public:
    bool valid(vector<vector<int>>& grid,int n, int r, int c){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]==1) return 0;
        return 1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]) return -1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> dr = {-1,-1,0,1,1,1,0,-1};
        vector<int> dc = {0,1,1,1,0,-1,-1,-1};
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        dist[0][0]=1;
        while(!pq.empty()){
            auto [r,c] = pq.top();
            pq.pop();
            for(int i=0; i<8; i++){
                if(valid(grid,n,r+dr[i], c+dc[i]) && dist[r][c] + 1 < dist[r+dr[i]][c+dc[i]]){
                    dist[r+dr[i]][c+dc[i]] = dist[r][c]+1;
                    pq.push({r+dr[i], c+dc[i]});
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};