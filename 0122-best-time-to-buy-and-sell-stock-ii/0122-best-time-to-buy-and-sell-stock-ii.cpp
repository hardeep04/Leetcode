class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int buy=v[0], sell=v[0];
        int ans=0;
        for(int i=1; i<n; i++){
            if(v[i]>sell){
                sell = v[i];
            }
            else if(v[i]<sell){
                ans += sell - buy;
                buy = v[i];
                sell = v[i];
            }
        }
        if(sell==v[n-1]) ans+=sell-buy;
        return ans;

    }
};