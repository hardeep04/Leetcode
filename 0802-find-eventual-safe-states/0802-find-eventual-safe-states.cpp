class Solution {
public:
    bool dfs(vector<vector<int>>& adj,vector<bool>& vis,int node,set<int>& s){
        if(s.count(node)) return 1;
        if(vis[node]) return 0;
        vis[node]=1;
        for(auto& neighbour:adj[node]){
            if(dfs(adj,vis,neighbour,s)==0) return 0;
        }
        s.insert(node);
        return 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        set<int> s;
        vector<bool> vis(n,0);
        for(int i=0; i<n; i++){
            if(adj[i].empty()){
                s.insert(i);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs(adj,vis,i,s);
        }
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};