class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        // in-degrees
        vector<int> indegree(num,0);
        for(auto &e : pre){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;
        for(int i=0; i<num; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(int neighbour : adj[curr]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        if(ans.size()==num) return ans;
        return {};
    }
};