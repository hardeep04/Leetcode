class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size(), ans=0;
        for(auto &v : grid){
            ans += upper_bound(v.rbegin(), v.rend(), -1) - v.rbegin();
        }
        return ans;
    }
};