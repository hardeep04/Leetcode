class Solution {
public:
    bool valid(int i, int j, int n, int m,vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]) return 0;
        return 1;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int i = p.first.first, j=p.first.second, dist=p.second;
            ans[i][j]=dist;
            if(valid(i-1,j,n,m,vis)){
                vis[i-1][j]=1;
                q.push({{i-1,j},dist+1});
            }
            if(valid(i+1,j,n,m,vis)){
                vis[i+1][j]=1;
                q.push({{i+1,j},dist+1});
            }
            if(valid(i,j-1,n,m,vis)){
                vis[i][j-1]=1;
                q.push({{i,j-1},dist+1});
            }
            if(valid(i,j+1,n,m,vis)){
                vis[i][j+1]=1;
                q.push({{i,j+1},dist+1});
            }
        }
        return ans;
    }
};