class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gs=g.size(), ss=s.size();
        int i=0, j=0;
        for(i=0; i<gs; i++){
            while(j<ss && s[j]<g[i]) j++;
            if(j==ss) break;
            if(j<ss && s[j]>=g[i]) j++;
        }
        return i;
    }
};