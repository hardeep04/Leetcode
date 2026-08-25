class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e:roads){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        ways[0] = 1;
        dist[0]=0;
        int mod=1e9+7;
        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();
            for(auto& nbr : adj[node]){
                if(dis + nbr.second < dist[nbr.first]){
                    dist[nbr.first] = dis+nbr.second;
                    pq.push({dist[nbr.first], nbr.first});
                    ways[nbr.first] = ways[node];
                }
                else if(dis + nbr.second == dist[nbr.first]){
                    ways[nbr.first] = (ways[nbr.first]%mod + ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};