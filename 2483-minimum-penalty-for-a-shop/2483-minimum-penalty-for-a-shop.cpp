class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.size();
        vector<int> close(n+1,0), open(n+1,0);
        for(int i=1; i<=n; i++){
            if(c[i-1]=='N') open[i] = open[i-1] + 1;
            else open[i] = open[i-1];
        }
        for(int i=n-1; i>=0; i--){
            if(c[i]=='Y') close[i] = close[i+1] + 1;
            else close[i] = close[i+1];
        }
        int minpenalty=INT_MAX, ans=0;
        for(int i=0; i<=n; i++){
            if(open[i]+close[i] < minpenalty){
                minpenalty = open[i]+close[i];
                ans = i;
            }
        }
        return ans;
    }
};