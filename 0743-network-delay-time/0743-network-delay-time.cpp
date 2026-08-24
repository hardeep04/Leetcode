class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e:times){
            adj[e[0]-1].push_back({e[1],e[2]});
        }
        vector<int> time(n, 1e9);
        time[k-1]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [t,node] = pq.top();
            pq.pop();
            for(auto& nbr:adj[node-1]){
                if(t+nbr.second < time[nbr.first-1]){
                    time[nbr.first-1] = t+nbr.second;
                    pq.push({time[nbr.first-1], nbr.first});
                }
            }
        }
        for(auto& i:time) if(i==1e9) return -1;
        return *max_element(time.begin(), time.end());
    }
};