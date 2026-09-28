class Solution {
public:
    int fun(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp){
        int n = mat.size(), m = mat[0].size();
        if (i<0 || j<0 || i >= n || j >= m || mat[i][j] == 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = 1 + min({fun(mat, i, j-1, dp), fun(mat, i-1, j-1, dp), fun(mat, i-1, j, dp)});
    }
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans=0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans+=fun(mat, i, j, dp);
            }
        }
        return ans;
    }
};