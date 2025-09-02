class Solution {
public:
    int numberOfPairs(vector<vector<int>>& v) {
        int n = v.size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int p=v[i][0], q=v[i][1], x=v[j][0], y=v[j][1];
                if(p<=x && q>=y || p>=x && q<=y){
                    int k;
                    for(k=0; k<n; k++){
                        if(k==i || k==j) continue;
                        int a = v[k][0], b = v[k][1];
                        if((a>=p && a<=x) || (a>=x && a<=p))
                        if((b>=q && b<=y) || (b>=y && b<=q)) break;
                    }
                    if(k==n) ans++;                    
                }
            }
        }
        return ans;
    }
};