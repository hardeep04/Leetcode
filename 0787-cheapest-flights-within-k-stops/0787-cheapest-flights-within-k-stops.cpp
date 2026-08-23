class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e:flights){
            adj[e[0]].push_back({e[1],e[2]});
        }
        queue<tuple<int,int,int>> q;
        q.push(make_tuple(0,src,k));
        vector<int> cost(n, 1e9);
        cost[src]=0;
        while(!q.empty()){
            auto [price, node, steps] = q.front();
            q.pop();
            if(steps < 0) continue;
            for(auto& p : adj[node]){
                if(price + p.second < cost[p.first]){
                    cost[p.first] = price+p.second;
                    q.push({cost[p.first], p.first, steps-1});
                }
            }
        }
        return cost[dst] == 1e9 ? -1 : cost[dst];
    }
};