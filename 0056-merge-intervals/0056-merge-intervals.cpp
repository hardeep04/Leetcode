class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int n=v.size();
        int s=v[0][0], e=v[0][1];
        ans.push_back({s,e});
        for(int i=1; i<n; i++){
            int l=v[i][0], r=v[i][1];
            if(l>=s && l<=e) ans.back()[1] = max(ans.back()[1], r);
            else ans.push_back({l,r});
            s=ans.back()[0];
            e=ans.back()[1]; 
        }
        return ans;
    }
};