class Solution {
public:
    // int fun(vector<vector<int>>& t, int i, int j,vector<vector<int>>& dp){
    //     if(i == t.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int left = t[i][j] + fun(t,i+1, j,dp);
    //     int right = t[i][j] + fun(t,i+1, j+1,dp);
    //     return dp[i][j] = min(left, right);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>> dp(n);
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<i+1; j++) dp[i].push_back(-1);
        // }
        // return fun(triangle,0, 0,dp);
        // for(int j=0; j<n; j++){
        //     dp[n-1][j] = triangle[n-1][j];
        // }
        vector<int> prev(n,-1);
        for(int j=0; j<n; j++){
            prev[j] = triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            vector<int> curr(n,-1);
            for(int j=0; j<i+1; j++){
                int left = triangle[i][j] + prev[j];
                int right = triangle[i][j] + prev[j+1];
                curr[j] = min(left, right);
            }
            prev = curr;
        }
        return prev[0];
    }
};