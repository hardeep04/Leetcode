class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n==1) return ans;
        ans.push_back({1,1});
        if(n==2) return ans;
        n-=2;
        int x=2;
        while(n--){
            vector<int> v;
            v.push_back(1);
            for(int i=0; i<x-1; i++){
                v.push_back(ans[x-1][i] + ans[x-1][i+1]);
            }
            v.push_back(1);
            ans.push_back(v);
            x++;
        }    
        return ans;
    }
};