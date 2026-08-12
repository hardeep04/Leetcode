class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& col, int node, int color){
        col[node] = color;

        for(auto it:adj[node]){
            if(col[it]==-1){
                if(dfs(adj,col,it,!color)==0) return 0;
            }
            else if(col[it] == color) return 0;
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n, -1);
        for(int i=0; i<n; i++){
            if(col[i]==-1){
                if(dfs(graph,col,i,0) == 0) return 0;
            }
        }
        return 1;
    }
};