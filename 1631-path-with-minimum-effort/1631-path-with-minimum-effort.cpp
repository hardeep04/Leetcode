class Solution {
public:    
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        dist[0][0]=0; 

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!pq.empty()){
            auto [diff,cell] = pq.top();
            int r = cell.first, c=cell.second;
            pq.pop();
            if(r==n-1 && c==m-1) return dist[r][c];
            for(int i=0; i<4; i++){
                int newr = r+dr[i], newc = c+dc[i];
                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    int temp = max(diff, abs(h[r][c] - h[newr][newc]));
                    if(temp < dist[newr][newc]){
                        dist[newr][newc] = temp;
                        pq.push({dist[newr][newc], {newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};