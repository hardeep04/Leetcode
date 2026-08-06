class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<pair<int,int>,int>> q;
        int n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j}, 0});
                }
            }
        }
        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            q.pop();
            int r=p.first.first, c=p.first.second;
            ans=max(ans,p.second);
            if(r>0 && grid[r-1][c]==1){
                grid[r-1][c]=2;
                q.push({{r-1,c}, p.second+1});
            }
            if(r<n-1 && grid[r+1][c]==1){
                grid[r+1][c]=2;
                q.push({{r+1,c}, p.second+1});
            }
            if(c>0 && grid[r][c-1]==1){
                grid[r][c-1]=2;
                q.push({{r,c-1},p.second+1});

            }
            if(c<m-1 && grid[r][c+1]==1){
                grid[r][c+1]=2;
                q.push({{r,c+1},p.second+1});
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt ? -1 : ans;
    }
};