class Solution {
public:
    void dfs(int n, vector<vector<int>>& v, vector<int>& vis, int node){
        vis[node]=1;
        for(int i=0; i<n; i++){
            if(v[node][i]==1 && !vis[i]){
                dfs(n,v,vis,i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> vis(n, 0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(n, v, vis, i);
            }
        }
        return ans;
    }
};