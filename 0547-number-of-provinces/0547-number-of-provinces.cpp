class Solution {
public:
    // void bfs(int n, vector<int> adj[], vector<int>& vis, int node){
    void bfs(int n, vector<vector<int>>& v, vector<int>& vis, int node){
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i=0; i<n; i++){
                if(v[curr][i] && !vis[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> vis(n, 0);
        int ans=0;
        // vector<int> adj[n];
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(i!=j && v[i][j]){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                // bfs(n,adj, vis, i);
                bfs(n, v, vis, i);
            }
        }
        return ans;
    }
};