class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gs=g.size(), ss=s.size(), j=0, ans=0;
        for(int i=0; i<gs; i++){
            while(j<ss && s[j]<g[i]) j++;
            if(j<ss && s[j]>=g[i]){
                ans++; j++;
            }
        }
        return ans;
    }
};